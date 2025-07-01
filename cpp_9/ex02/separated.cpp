#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <sys/time.h>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <utility> // For std::pair, std::make_pair
#include <iomanip> // For std::fixed, std::setprecision

class PmergeMe {
private:
    std::vector<int> _numbers;

    double getCurrentTime() const {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec * 1000000.0 + tv.tv_usec;
    }

    //returning value is what we will use to insert the item at (before)
    template<typename Iterator>
    Iterator binarySearchInsert(Iterator begin, Iterator end, int value) const {
        Iterator low = begin;
        Iterator high = end; // Search range is [begin, end)

        while (low < high) {
            // C++98 standard says Iterators are RandomAccessIterator for vector/deque
            // low + (high - low) / 2 is valid for RandomAccessIterator
            Iterator mid = low + (std::distance(low, high) / 2); // Use std::distance for clarity, works for RA iterators
            if (*mid < value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low; // 'low' is the insertion point where value should be placed
    }

void fordJohnsonSortVector(std::vector<int>& c) 
{
        if (c.size() <= 1)
            return;

        // Store pairs along with their original index to find the first loser later
        std::vector<std::pair<std::pair<int, int>, size_t> > indexedPairs;
        bool hasOdd = c.size() % 2 == 1;
        int oddElement = hasOdd ? c.back() : -1;

        for (size_t i = 0; i + 1 < c.size(); i += 2) {
            // Store pair (winner, loser) and its pair index
            if (c[i] > c[i + 1])
                indexedPairs.push_back(std::make_pair(std::make_pair(c[i], c[i + 1]), i / 2));
            else
                indexedPairs.push_back(std::make_pair(std::make_pair(c[i + 1], c[i]), i / 2));
        }

        // Extract winners for recursive sorting
        std::vector<int> winners;
        for (size_t i = 0; i < indexedPairs.size(); ++i) {
            winners.push_back(indexedPairs[i].first.first);
        }
        fordJohnsonSortVector(winners); // Recursively sort the winner values

        // Build main chain starting with sorted winners
        std::vector<int> mainChain;
        for(size_t i = 0; i < winners.size(); ++i) {
            mainChain.push_back(winners[i]);
        }

        // Keep track of which original pair indices have had their losers inserted
        std::vector<bool> inserted(indexedPairs.size(), false);

        // --- Simplified Insertion Phase ---

        // 1. Insert the first loser (paired with the smallest winner)
        int smallestWinner = winners[0];
        size_t firstLoserPairIdx = 0;
        int firstLoserValue = -1;

        for (size_t i = 0; i < indexedPairs.size(); ++i) {
            if (indexedPairs[i].first.first == smallestWinner) {
                 firstLoserPairIdx = indexedPairs[i].second;
                 firstLoserValue = indexedPairs[i].first.second;
                break;
            }
        }

        mainChain.insert(mainChain.begin(), firstLoserValue);
        inserted[firstLoserPairIdx] = true;

        // 2. Insert remaining losers in simple sequential order
        for (size_t i = 0; i < indexedPairs.size(); ++i) {
            if (!inserted[i]) {
                int loser = indexedPairs[i].first.second;
                int winner = indexedPairs[i].first.first;

                // Find position of winner in main chain
                std::vector<int>::iterator winnerPos = std::find(mainChain.begin(), mainChain.end(), winner);

                // Insert loser before its winner using binary search
                std::vector<int>::iterator insertPos = binarySearchInsert(mainChain.begin(), winnerPos, loser);
                mainChain.insert(insertPos, loser);

                inserted[i] = true;
            }
        }

        // 3. Insert odd element if exists
        if (hasOdd) {
            std::vector<int>::iterator insertPos = binarySearchInsert(mainChain.begin(), mainChain.end(), oddElement);
            mainChain.insert(insertPos, oddElement);
        }

        c = mainChain; // Replace the original container with the sorted one
}

void fordJohnsonSortDeque(std::deque<int>& c) {
    if (c.size() <= 1)
        return;

    // Store pairs along with their original index to find the first loser later
    std::vector<std::pair<std::pair<int, int>, size_t> > indexedPairs;
    bool hasOdd = c.size() % 2 == 1;
    int oddElement = hasOdd ? c.back() : -1;

    for (size_t i = 0; i + 1 < c.size(); i += 2) {
        // Store pair (winner, loser) and its pair index
        if (c[i] > c[i + 1])
            indexedPairs.push_back(std::make_pair(std::make_pair(c[i], c[i + 1]), i / 2));
        else
            indexedPairs.push_back(std::make_pair(std::make_pair(c[i + 1], c[i]), i / 2));
    }

    // Extract winners for recursive sorting
    std::deque<int> winners;
    for (size_t i = 0; i < indexedPairs.size(); ++i) {
        winners.push_back(indexedPairs[i].first.first);
    }
    fordJohnsonSortDeque(winners); // Recursively sort the winner values

    // Build main chain starting with sorted winners
    std::deque<int> mainChain;
    for(size_t i = 0; i < winners.size(); ++i) {
        mainChain.push_back(winners[i]);
    }

    // Keep track of which original pair indices have had their losers inserted
    std::vector<bool> inserted(indexedPairs.size(), false);

    // --- Simplified Insertion Phase ---

    // 1. Insert the first loser (paired with the smallest winner)
    int smallestWinner = winners[0];
    size_t firstLoserPairIdx = 0;
    int firstLoserValue = -1;

    for (size_t i = 0; i < indexedPairs.size(); ++i) {
        if (indexedPairs[i].first.first == smallestWinner) {
                firstLoserPairIdx = indexedPairs[i].second;
                firstLoserValue = indexedPairs[i].first.second;
            break;
        }
    }

    mainChain.insert(mainChain.begin(), firstLoserValue);
    inserted[firstLoserPairIdx] = true;

    // 2. Insert remaining losers in simple sequential order
    for (size_t i = 0; i < indexedPairs.size(); ++i) {
        if (!inserted[i]) {
            int loser = indexedPairs[i].first.second;
            int winner = indexedPairs[i].first.first;

            // Find position of winner in main chain
            std::deque<int>::iterator winnerPos = std::find(mainChain.begin(), mainChain.end(), winner);

            // Insert loser before its winner using binary search
            std::deque<int>::iterator insertPos = binarySearchInsert(mainChain.begin(), winnerPos, loser);
            mainChain.insert(insertPos, loser);

            inserted[i] = true;
        }
    }

    // 3. Insert odd element if exists
    if (hasOdd) {
        std::deque<int>::iterator insertPos = binarySearchInsert(mainChain.begin(), mainChain.end(), oddElement);
        mainChain.insert(insertPos, oddElement);
    }

    c = mainChain; // Replace the original container with the sorted one
}


public:
    bool parseInput(int argc, char** argv) {
        if (argc < 2) {
            std::cerr << "Error" << std::endl;
            return false;
        }

        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];

            if (arg.empty()) {
                 std::cerr << "Error" << std::endl;
                 return false;
            }

            // Check for non-digit characters or leading sign (allow only digits)
            for (size_t j = 0; j < arg.length(); ++j) {
                if (!std::isdigit(arg[j])) {
                    std::cerr << "Error" << std::endl;
                    return false;
                }
            }

            // Check for leading zeros on multi-digit numbers
            if (arg.length() > 1 && arg[0] == '0') {
                std::cerr << "Error" << std::endl;
                return false;
            }

            std::stringstream ss(arg);
            long num_long;
            ss >> num_long;

            // Check if conversion failed or if there's extra data in the stringstream
            if (ss.fail() || !ss.eof()) {
                std::cerr << "Error" << std::endl;
                return false;
            }

            // Check for negative numbers (already excluded by isdigit but good practice)
            // Check for overflow against int max
            if (num_long < 0 || num_long > 2147483647L) { // Use L suffix for long literal
                std::cerr << "Error" << std::endl;
                return false;
            }

            int num = static_cast<int>(num_long);

            _numbers.push_back(num);
        }

        if (_numbers.empty()) {
            // This case is actually covered by argc < 2, but safety
            std::cerr << "Error" << std::endl;
            return false;
        }

        return true;
    }

    // Display sequence with truncation
    template<typename Container>
    void displaySequence(const std::string& label, const Container& c) const {
        std::cout << label;
        size_t display_limit = 10;
       //size_t truncate_threshold = 10; // If size is > 10, truncate

        for (size_t i = 0; i < c.size(); ++i) {
            if (i > 0)
                std::cout << " ";
            std::cout << c[i];
            if (i >= display_limit - 1){//&& c.size() > truncate_threshold) {
                std::cout << " [...]";
                break;
            }
        }
        std::cout << std::endl;
    }

    void run() {
        if (_numbers.empty()) {
            // Already handled by parseInput returning false
            return;
        }

        displaySequence("Before: ", _numbers);

        // Sort with std::vector
        std::vector<int> vectorCopy = _numbers;
        double startTimeVector = getCurrentTime();
        fordJohnsonSortVector(vectorCopy); // Use the template function
        double vectorTime = getCurrentTime() - startTimeVector;

        // Sort with std::deque
        std::deque<int> dequeCopy(_numbers.begin(), _numbers.end());
        double startTimeDeque = getCurrentTime();
        fordJohnsonSortDeque(dequeCopy); // Use the template function
        double dequeTime = getCurrentTime() - startTimeDeque;

        // Display sorted sequence (can use either vectorCopy or dequeCopy)
        displaySequence("After:  ", vectorCopy); // Or dequeCopy

        // Verify sorted state (optional check)
        // if (!std::is_sorted(vectorCopy.begin(), vectorCopy.end())) {
        //      std::cerr << "Error: Vector not sorted correctly!" << std::endl;
        // }
         // if (!std::is_sorted(dequeCopy.begin(), dequeCopy.end())) {
        //      std::cerr << "Error: Deque not sorted correctly!" << std::endl;
        // }


        // Display timing information
        std::cout.precision(5); // Use 5 digits after decimal point
        std::cout << std::fixed; // Use fixed-point notation (not scientific)
        std::cout << "Time to process a range of " << _numbers.size()
                  << " elements with std::vector : " << vectorTime << " us" << std::endl;
        std::cout << "Time to process a range of " << _numbers.size()
                  << " elements with std::deque  : " << dequeTime << " us" << std::endl;
    }
};

int main(int argc, char** argv) {
    PmergeMe pmerge;

    if (!pmerge.parseInput(argc, argv)) {
        // Error message is printed inside parseInput
        return EXIT_FAILURE;
    }

    pmerge.run();
    return 0;
}