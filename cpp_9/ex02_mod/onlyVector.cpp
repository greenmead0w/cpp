#include "PmergeMe.hpp"

// Orthodox Canonical Form
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

// Parse and validate input arguments
bool PmergeMe::parseAndValidate(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No arguments provided" << std::endl;
        return false;
    }

    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        // Check if string is empty
        if (arg.empty()) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        // Check for non-digit characters (except leading +)
        size_t start = 0;
        if (arg[0] == '+') {
            start = 1;
        }
        
        for (size_t j = start; j < arg.length(); j++) {
            if (!isdigit(arg[j])) {
                std::cerr << "Error" << std::endl;
                return false;
            }
        }
        
        // Convert to integer
        std::stringstream ss(arg);
        long num;
        ss >> num;
        
        // Check for negative numbers or numbers too large
        if (num < 0 || num > 2147483647) {
            std::cerr << "Error" << std::endl;
            return false;
        }
        
        this->vectorData.push_back(static_cast<int>(num));
        this->dequeData.push_back(static_cast<int>(num));
    }
    
    return true;
}

// Generate Jacobsthal numbers up to a certain size
std::vector<int> PmergeMe::generateJacobsthalSequence(size_t size) {
    std::vector<int> jacobsthal;

    int prev = 1; // J_1
    int curr = 1; // J_2

    // We want to generate starting from J_3 = 3
    // J_n = J_{n-1} + 2 * J_{n-2}
    while (curr < static_cast<int>(size)) {
        int next = curr + 2 * prev;
        jacobsthal.push_back(next);
        prev = curr;
        curr = next;
    }

    return jacobsthal;
}

// Generate insertion order based on Jacobsthal sequence
std::vector<size_t> PmergeMe::generateInsertionOrder(size_t pendSize) {
    std::vector<size_t> insertionOrder;
    // We already inserted pendChain[0].
    // We need to insert pendChain[1]...pendChain[pendSize-1].
    
    std::vector<int> jacobsthal = generateJacobsthalSequence(pendSize);
    
    // lastBound is the index of the last element already part of the chain logic.
    // Initially, we consider index 0 done.
    size_t lastBound = 0; 
    
    for (size_t i = 0; i < jacobsthal.size(); i++) {
        size_t currentBound = jacobsthal[i] - 1; // Convert 1-based count to 0-based index
        
        if (currentBound >= pendSize) 
            currentBound = pendSize - 1;

        // Add indices from currentBound down to lastBound + 1
        while (currentBound > lastBound) {
            insertionOrder.push_back(currentBound);
            currentBound--;
        }
        
        lastBound = jacobsthal[i] - 1;
        if (lastBound >= pendSize - 1) break;
    }
    
    // Fill any remaining if Jacobsthal sequence ended too early (rare with generate logic)
    while (lastBound < pendSize - 1) {
        lastBound++;
        insertionOrder.push_back(lastBound);
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
    std::vector<std::pair<int, int> > pairs;
    bool hasStraggler = (n % 2 == 1);
    int straggler = -1;
    
    if (hasStraggler) {
        straggler = arr[n - 1];
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
    
    winners = fordJohnsonSortVector(winners);
    
    // Step 3: Rearrange pairs according to sorted winners
    std::vector<std::pair<int, int> > sortedPairs;
    std::vector<bool> visited(pairs.size(), false); // Track used pairs

    for (size_t i = 0; i < winners.size(); i++) {
        for (size_t j = 0; j < pairs.size(); j++) {
            // Match value AND ensure we haven't used this specific pair instance yet
            if (!visited[j] && pairs[j].first == winners[i]) {
                sortedPairs.push_back(pairs[j]);
                visited[j] = true; // Mark as used
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
    // Step 5: Insertion
    if (!pendChain.empty()) {
        // 1. Insert the first pend element
        mainChain.insert(mainChain.begin(), pendChain[0]);
        size_t addedCount = 1; // We just added one

        // 2. Generate insertion order for remaining elements (indices 1 to size-1)
        std::vector<size_t> insertionOrder = generateInsertionOrder(pendChain.size());
        

        for (size_t i = 0; i < insertionOrder.size(); i++) {
            size_t pendIndex = insertionOrder[i]; // The original index in pendChain
            int valueToInsert = pendChain[pendIndex];
            
            // We need to insert 'valueToInsert' into 'mainChain'.
            // Its partner (the value that beat it) is 'winners[pendIndex]'.
            // Since 'mainChain' contains 'winners' + inserted elements, 
            // the partner is now located at index: pendIndex + addedCount.
            
            size_t searchLimit = pendIndex + addedCount;
            
            // Find position
            size_t pos = binarySearchPosition(mainChain, valueToInsert, searchLimit);
            
            // Insert
            mainChain.insert(mainChain.begin() + pos, valueToInsert);
            
            // Update added count
            addedCount++;
        }
    }
    
    // Step 6: Insert straggler if exists
    if (hasStraggler) {
        size_t pos = binarySearchPosition(mainChain, straggler, mainChain.size());
        mainChain.insert(mainChain.begin() + pos, straggler);
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

// Main sorting function
void PmergeMe::sort(int argc, char** argv) {
    // Parse and validate input
    if (!parseAndValidate(argc, argv)) {
        return;
    }
    
    // Display "Before"
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
    
    // Display "After"
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
}
