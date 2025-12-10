#include "PmergeMe.hpp"

/**********CANONICAL*************
********************************/
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    this->vectorData = other.vectorData;
    this->dequeData = other.dequeData;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        this->vectorData = other.vectorData;
        this->dequeData = other.dequeData;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

/********END CANONICAL********
******************************/


// Parse, validate and store input
bool PmergeMe::parseAndValidate(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "Error: No numbers provided" << std::endl;
        return false;
    }

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg.empty()) {
            std::cout << "Error: empty argument" << std::endl;
            return false;
        }
        
        // leading '+' is accepted
        size_t start = 0;
        if (arg[0] == '+') {
            start = 1;
        }
        
        // notación científica peta
        for (size_t j = start; j < arg.length(); j++) {
            if (!isdigit(arg[j])) {
                std::cout << "Error: non digit argument" << std::endl;
                return false;
            }
        }
        
        // Convert to integer
        std::stringstream ss(arg);
        long num;
        ss >> num;
        
        if (num < 0 || num > 2147483647) {
            std::cout << "Error: number is negative or overflows" << std::endl;
            return false;
        }
        
        this->vectorData.push_back(static_cast<int>(num));
        this->dequeData.push_back(static_cast<int>(num));
    }
    
    return true;
}

// Generate Jacobsthal numbers up to a certain size
std::vector<int> PmergeMe::generateJacobsthalSequence(size_t size) {

    //std::cout << "size is: " << size << std::endl;
    std::vector<int> jacobsthal;
    
    if (size == 0)
        return jacobsthal;
    
    //J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
    size_t j0 = 0;
    size_t j1 = 1;
    
    //might need to add "<="
    while (j1 < size) {
        jacobsthal.push_back(j1);
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
    /*std::cout << "jacobsthal sequence is: ";
    for (std::vector<int>::const_iterator it = jacobsthal.begin(); it != jacobsthal.end(); ++it)
        std::cout << *it << ' ';
    std::cout << std::endl;*/

    return jacobsthal;
}

// Generate insertion order based on Jacobsthal sequence
std::vector<size_t> PmergeMe::generateInsertionOrder(size_t pendSize) {
    std::vector<size_t> insertionOrder;
    
    if (pendSize == 0)
        return insertionOrder;
    
    // Generate Jacobsthal sequence
    std::vector<int> jacobsthal = generateJacobsthalSequence(pendSize + 1);
    
    size_t lastIndex = 0;
    
    for (size_t i = 0; i < jacobsthal.size(); i++) {
        size_t jacobIndex = static_cast<size_t>(jacobsthal[i]);
        
        // If this Jacobsthal number is within bounds
        if (jacobIndex <= pendSize) {
            // Add from jacobIndex down to lastIndex + 1
            for (size_t j = jacobIndex; j > lastIndex; j--) {
                insertionOrder.push_back(j - 1); // Convert to 0-based index
            }
            lastIndex = jacobIndex;
        }
    }
    
    // Add any remaining elements
    for (size_t i = lastIndex; i < pendSize; i++) {
        insertionOrder.push_back(i);
    }
    
    return insertionOrder;
}

// Binary search to find insertion position in sorted array
size_t PmergeMe::binarySearchPosition(const std::vector<int>& main, int value, size_t end) {
    size_t left = 0;
    size_t right = end;
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (main[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

// Ford-Johnson sort implementation for vector
std::vector<int> PmergeMe::fordJohnsonSortVector(std::vector<int> arr) {
    size_t n = arr.size();
    
    // Base case: arrays of size 0 or 1 are already sorted
    if (n <= 1) {
        return arr;
    }
    
    // Step 1: Group elements into pairs and sort each pair
    std::vector<std::pair<int, int> > pairs; //dynamic array where each element is a pair. pair is a struct definec in std
    bool isOdd = (n % 2 == 1);
    int odd = -1;
    
    if (isOdd) {
        odd = arr[n - 1];
    }
    
    // Create pairs and ensure first element is larger (winner)
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
    }
    
    // Step 2: Recursively sort the winners (first elements of pairs)
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); i++) {
        winners.push_back(pairs[i].first);
    }
    
    winners = fordJohnsonSortVector(winners); //recursion
    
    // Step 3: Rearrange pairs according to sorted winners
    std::vector<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < winners.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].first == winners[i]) {
                sortedPairs.push_back(pairs[j]);
                break;
            }
        }
    }
    
    // Step 4: Build main chain (winners) and pend chain (losers)
    std::vector<int> mainChain;
    std::vector<int> pendChain;
    
    for (size_t i = 0; i < sortedPairs.size(); i++) {
        mainChain.push_back(sortedPairs[i].first);
        pendChain.push_back(sortedPairs[i].second);
    }
    
    // The first element of pend is always smaller than first of main, insert it at beginning
    if (!pendChain.empty()) {
        mainChain.insert(mainChain.begin(), pendChain[0]);
        
        // Step 5: Insert remaining pend elements using Jacobsthal sequence
        std::vector<size_t> insertionOrder = generateInsertionOrder(pendChain.size() - 1);
        
        for (size_t i = 0; i < insertionOrder.size(); i++) {
            size_t pendIndex = insertionOrder[i] + 1; // +1 because we already inserted first element
            int valueToInsert = pendChain[pendIndex];
            
            // Find position using binary search up to the corresponding position in main
            size_t searchLimit = pendIndex + i + 1; // Adjust search limit as we insert
            if (searchLimit > mainChain.size()) {
                searchLimit = mainChain.size();
            }
            
            size_t pos = binarySearchPosition(mainChain, valueToInsert, searchLimit);
            mainChain.insert(mainChain.begin() + pos, valueToInsert);
        }
    }
    
    // Step 6: Insert odd if exists
    if (isOdd) {
        size_t pos = binarySearchPosition(mainChain, odd, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, odd);
    }
    
    return mainChain;
}

// Binary search for deque
size_t PmergeMe::binarySearchPositionDeque(const std::deque<int>& main, int value, size_t end) {
    size_t left = 0;
    size_t right = end;
    
    while (left < right) {
        size_t mid = left + (right - left) / 2;
        if (main[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    return left;
}

// Ford-Johnson sort implementation for deque
std::deque<int> PmergeMe::fordJohnsonSortDeque(std::deque<int> arr) {
    size_t n = arr.size();
    
    // Base case
    if (n <= 1) {
        return arr;
    }
    
    // Step 1: Group elements into pairs and sort each pair
    std::deque<std::pair<int, int> > pairs;
    bool isOdd = (n % 2 == 1);
    int odd = 0;
    
    if (isOdd) {
        odd = arr[n - 1];
    }
    
    for (size_t i = 0; i + 1 < n; i += 2) {
        if (arr[i] > arr[i + 1]) {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        } else {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
        }
    }
    
    // Step 2: Recursively sort the winners
    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); i++) {
        winners.push_back(pairs[i].first);
    }
    
    winners = fordJohnsonSortDeque(winners);
    
    // Step 3: Rearrange pairs according to sorted winners
    std::deque<std::pair<int, int> > sortedPairs;
    for (size_t i = 0; i < winners.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            if (pairs[j].first == winners[i]) {
                sortedPairs.push_back(pairs[j]);
                break;
            }
        }
    }
    
    // Step 4: Build main and pend chains
    std::deque<int> mainChain;
    std::deque<int> pendChain;
    
    for (size_t i = 0; i < sortedPairs.size(); i++) {
        mainChain.push_back(sortedPairs[i].first);
        pendChain.push_back(sortedPairs[i].second);
    }
    
    // Insert first pend element
    if (!pendChain.empty()) {
        mainChain.push_front(pendChain[0]);
        
        // Step 5: Insert remaining pend elements using Jacobsthal sequence
        std::vector<size_t> insertionOrder = generateInsertionOrder(pendChain.size() - 1);
        
        for (size_t i = 0; i < insertionOrder.size(); i++) {
            size_t pendIndex = insertionOrder[i] + 1;
            int valueToInsert = pendChain[pendIndex];
            
            size_t searchLimit = pendIndex + i + 1;
            if (searchLimit > mainChain.size()) {
                searchLimit = mainChain.size();
            }
            
            size_t pos = binarySearchPositionDeque(mainChain, valueToInsert, searchLimit);
            mainChain.insert(mainChain.begin() + pos, valueToInsert);
        }
    }
    
    // Step 6: Insert odd if exists
    if (isOdd) {
        size_t pos = binarySearchPositionDeque(mainChain, odd, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, odd);
    }
    
    return mainChain;
}


void PmergeMe::sort(int argc, char** argv) {
    if (!parseAndValidate(argc, argv)) {
        return;
    }
    
    // Print "Before"
    std::cout << "Before: ";
    for (size_t i = 0; i < this->vectorData.size(); i++) {
        std::cout << this->vectorData[i];
        if (i < this->vectorData.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    
    // Sort with vector and measure time
    clock_t startVector = clock();
    std::vector<int> sortedVector = fordJohnsonSortVector(this->vectorData);
    clock_t endVector = clock();
    double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000;
    
    // Sort with deque and measure time
    // clock_t startDeque = clock();
    // std::deque<int> sortedDeque = fordJohnsonSortDeque(this->dequeData);
    // clock_t endDeque = clock();
    // double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000;
    
    //print "After"
    std::cout << "After: ";
    for (size_t i = 0; i < sortedVector.size(); i++) {
        std::cout << sortedVector[i];
        if (i < sortedVector.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    
    // Display timing information
    std::cout << "Time to process a range of " << this->vectorData.size() 
              << " elements with std::vector : " << timeVector << " us" << std::endl;
    // std::cout << "Time to process a range of " << this->dequeData.size() 
    //           << " elements with std::deque : " << timeDeque << " us" << std::endl;
}