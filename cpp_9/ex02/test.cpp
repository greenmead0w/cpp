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

    // Generate Jacobsthal numbers up to a given limit
    std::vector<size_t> generateJacobsthalSeq(size_t limit) {
        std::vector<size_t> jacobsthal;
        if (limit <= 0) return jacobsthal;
        
        jacobsthal.push_back(1);
        if (limit == 1) return jacobsthal;
        
        jacobsthal.push_back(1);
        if (limit == 2) return jacobsthal;
        
        size_t a = 1, b = 1;
        while (true) {
            size_t next = a + 2 * b;
            if (next > limit) break;
            jacobsthal.push_back(next);
            a = b;
            b = next;
        }
        return jacobsthal;
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

    template<typename Container>
    void fordJohnsonSort(Container& c) {
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

        // if (indexedPairs.empty() && !hasOdd)
        //     return; // Should not happen if size > 1

        //  if (indexedPairs.empty() && hasOdd) {
        //      // Only odd element, already sorted
        //      c.clear();
        //      c.push_back(oddElement);
        //      return;
        //  }


        // Extract winners for recursive sorting
        // We sort based on the winner value, but need the original pair index later
        std::vector<std::pair<int, size_t> > indexedWinners;
        for (size_t i = 0; i < indexedPairs.size(); ++i) {
            indexedWinners.push_back(std::make_pair(indexedPairs[i].first.first, indexedPairs[i].second));
        }

        // we only need the smallest winner to find the first loser
        std::vector<int> winners;
        for (size_t i = 0; i < indexedPairs.size(); ++i) {
            winners.push_back(indexedPairs[i].first.first);
        }
        fordJohnsonSort(winners); // Recursively sort the winner values

        // Build main chain starting with sorted winners
        Container mainChain;
        for(size_t i = 0; i < winners.size(); ++i) {
            mainChain.push_back(winners[i]);
        }

        // Keep track of which original pair indices (0 to pairs.size()-1) have had their losers inserted
        std::vector<bool> inserted(indexedPairs.size(), false);

        // --- Insertion Phase ---

        // 1. Insert the first loser (paired with the smallest winner)
        // Find the original pair index corresponding to the smallest winner (winners[0])
        int smallestWinner = winners[0];
        size_t firstLoserPairIdx = 0; // This will be the index in the `indexedPairs` vector
        int firstLoserValue = -1;

        for (size_t i = 0; i < indexedPairs.size(); ++i) {
            if (indexedPairs[i].first.first == smallestWinner) {
                 firstLoserPairIdx = indexedPairs[i].second; // Get the *original* pair index (0 to N/2-1)
                 firstLoserValue = indexedPairs[i].first.second;
                break; // Found the pair with the smallest winner
            }
        }

        mainChain.insert(mainChain.begin(), firstLoserValue);
        inserted[firstLoserPairIdx] = true; // Mark the original pair index as inserted

        // 2. Insert remaining losers using Jacobsthal sequence ordering
        // The sequence of *original pair indices* to insert *after* the first is
        // derived from Jacobsthal numbers: J(1)-1, then J(2)-1, J(2)-2, ..., J(1), ... (0-based)
        // Which is indices: 0, then 2, 1, then 4, 3, ...

        // Generate Jacobsthal sequence J(1), J(2), J(3)...
        std::vector<size_t> jacobSeq = generateJacobsthalSeq(indexedPairs.size()); // J(1), J(2), ...

        // Keep track of which indices from the *Jacobsthal sequence* we have processed
        // This helps generate the 0, 2, 1, 4, 3, ... order
        std::vector<size_t> insertionOrderIndices;
        size_t currentJacobstalIndex = 1; // Start with J(1) = 1

        while(true) {
             size_t J_k_minus_1 = (currentJacobstalIndex >= 2) ? jacobSeq[currentJacobstalIndex - 2] : 0; // J(k-1), J(0)=0
             size_t J_k = jacobSeq[currentJacobstalIndex - 1]; // J(k)

             // Add indices from J(k)-1 down to J(k-1) (0-based original pair indices)
             // Ensure indices are within the bounds of indexedPairs (0 to size()-1)
             size_t upper_bound_1based = std::min((size_t)indexedPairs.size(), J_k);
             size_t lower_bound_1based = J_k_minus_1 + 1;

             bool added_indices_in_this_block = false;
             if (upper_bound_1based >= lower_bound_1based) { // Check if the range is valid
                for (size_t originalPairIndex = upper_bound_1based - 1; ; --originalPairIndex) {
                    if (originalPairIndex < indexedPairs.size()) { // Ensure index is valid
                         insertionOrderIndices.push_back(originalPairIndex);
                         added_indices_in_this_block = true;
                    }
                     if (originalPairIndex == lower_bound_1based - 1 || originalPairIndex == 0) break; // Stop condition for decreasing loop
                }
             }

             currentJacobstalIndex++;
             if (!added_indices_in_this_block && J_k >= indexedPairs.size()) {
                 // If no indices were added in the last block and J_k is already >= size, we likely covered all relevant indices
                 break;
             }
             if (currentJacobstalIndex > jacobSeq.size() + 2) break; // Safety break
        }


        // Now iterate through the generated insertion order and insert losers
        for (size_t i = 0; i < insertionOrderIndices.size(); ++i) {
            size_t originalPairIndex = insertionOrderIndices[i];

             // Ensure index is valid (should be if generator is correct, but safety)
            if (originalPairIndex >= indexedPairs.size()) continue;

            if (!inserted[originalPairIndex]) {
                int loser = indexedPairs[originalPairIndex].first.second; // Loser value
                int winner = indexedPairs[originalPairIndex].first.first; // Winner value

                // Find position of winner in main chain
                 typename Container::iterator winnerPos = std::find(mainChain.begin(), mainChain.end(), winner);

                // Insert loser before its winner using binary search on the sorted sub-sequence
                 typename Container::iterator insertPos = binarySearchInsert(mainChain.begin(), winnerPos, loser);
                mainChain.insert(insertPos, loser);

                inserted[originalPairIndex] = true; // Mark as inserted
            }
        }

        // 3. Insert any remaining uninserted losers (covers indices not reached by Jacobsthal sequence logic)
        // This loop is a safety net and might not be strictly necessary if Jacobsthal logic is perfect
        // and covers all indices up to pairs.size()-1, but it's harmless.
        for (size_t i = 0; i < indexedPairs.size(); ++i) {
             if (!inserted[i]) {
                 int loser = indexedPairs[i].first.second; // Loser value
                 int winner = indexedPairs[i].first.first; // Winner value

                  typename Container::iterator winnerPos = std::find(mainChain.begin(), mainChain.end(), winner);
                  typename Container::iterator insertPos = binarySearchInsert(mainChain.begin(), winnerPos, loser);
                 mainChain.insert(insertPos, loser);
                 inserted[i] = true;
             }
         }


        // 4. Insert odd if exists
        if (hasOdd) {
            typename Container::iterator insertPos = binarySearchInsert(mainChain.begin(), mainChain.end(), oddElement);
            mainChain.insert(insertPos, oddElement);
        }

        // c = mainChain; // Replace the original container with the sorted one
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

             // Optional: Check for duplicates if needed, though F-J handles them
             // for (size_t k = 0; k < _numbers.size(); ++k) {
             //     if (_numbers[k] == num) {
             //         std::cerr << "Error: Duplicates not allowed (optional check)" << std::endl;
             //         return false;
             //     }
             // }

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
        fordJohnsonSort(vectorCopy); // Use the template function
        double vectorTime = getCurrentTime() - startTimeVector;

        // Sort with std::deque
        std::deque<int> dequeCopy(_numbers.begin(), _numbers.end());
        double startTimeDeque = getCurrentTime();
        fordJohnsonSort(dequeCopy); // Use the template function
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