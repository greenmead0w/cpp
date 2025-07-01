
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <sstream>
#include <sys/time.h>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <utility>
#include <iomanip>

class PmergeMe {
private:
    std::vector<int> _numbers;

    double getCurrentTime() const {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec * 1000000.0 + tv.tv_usec;
    }

    // Generate Jacobsthal numbers: J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
    // But for Ford-Johnson, we typically use the sequence starting from J(1)=1
    std::vector<size_t> generateJacobsthalSeq(size_t maxSize) {
        std::vector<size_t> seq;
        if (maxSize == 0) return seq;
        
        seq.push_back(1); // J(1) = 1
        if (maxSize == 1) return seq;
        
        seq.push_back(3); // J(2) = 3
        if (maxSize <= 3) return seq;
        
        size_t prev_prev = 1; // J(1)
        size_t prev = 3;      // J(2)
        
        while (true) {
            size_t next = prev + 2 * prev_prev; // J(n) = J(n-1) + 2*J(n-2)
            if (next > maxSize) break;
            seq.push_back(next);
            prev_prev = prev;
            prev = next;
        }
        
        return seq;
    }

    template<typename Iterator>
    Iterator binarySearchInsert(Iterator begin, Iterator end, int value) const {
        Iterator low = begin;
        Iterator high = end;

        while (low < high) {
            Iterator mid = low + (high - low) / 2;
            if (*mid < value) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    void fordJohnsonVector(std::vector<int>& vec) {
        if (vec.size() <= 1) return;

        // Handle pairs and odd element
        std::vector<std::pair<int, int> > pairs;
        int straggler = -1;
        bool hasStraggler = false;

        // Create pairs, ensuring first element of pair is larger
        for (size_t i = 0; i + 1 < vec.size(); i += 2) {
            if (vec[i] > vec[i + 1]) {
                pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
            } else {
                pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
            }
        }

        // Handle odd element
        if (vec.size() % 2 == 1) {
            straggler = vec.back();
            hasStraggler = true;
        }

        if (pairs.empty()) {
            return; // Only one element, already sorted
        }

        // Extract winners (larger elements) for recursive sorting
        std::vector<int> winners;
        for (size_t i = 0; i < pairs.size(); ++i) {
            winners.push_back(pairs[i].first);
        }

        // Recursively sort winners
        fordJohnsonVector(winners);

        // Build main chain starting with winners
        std::vector<int> mainChain = winners;

        // Insert the first loser (paired with smallest winner) at the beginning
        mainChain.insert(mainChain.begin(), pairs[0].second);

        // Generate Jacobsthal sequence for optimal insertion order
        std::vector<size_t> jacobSeq = generateJacobsthalSeq(pairs.size());

        // Keep track of which losers have been inserted
        std::vector<bool> inserted(pairs.size(), false);
        inserted[0] = true; // First loser already inserted

        // Insert remaining losers using Jacobsthal sequence
        for (size_t seqIdx = 0; seqIdx < jacobSeq.size(); ++seqIdx) {
            size_t jacobNum = jacobSeq[seqIdx];
            size_t prevJacobNum = (seqIdx == 0) ? 1 : jacobSeq[seqIdx - 1];

            // Insert losers from jacobNum-1 down to prevJacobNum (in reverse order)
            for (size_t idx = std::min(jacobNum, pairs.size()); idx > prevJacobNum; --idx) {
                size_t loserIdx = idx - 1; // Convert to 0-based index
                
                if (loserIdx < pairs.size() && !inserted[loserIdx]) {
                    int loser = pairs[loserIdx].second;
                    int winner = pairs[loserIdx].first;

                    // Find position of winner in main chain
                    std::vector<int>::iterator winnerPos = std::find(mainChain.begin(), mainChain.end(), winner);
                    
                    // Insert loser before its winner using binary search
                    std::vector<int>::iterator insertPos = binarySearchInsert(mainChain.begin(), winnerPos, loser);
                    mainChain.insert(insertPos, loser);
                    
                    inserted[loserIdx] = true;
                }
            }
        }

        // Insert any remaining uninserted losers
        for (size_t i = 1; i < pairs.size(); ++i) {
            if (!inserted[i]) {
                int loser = pairs[i].second;
                int winner = pairs[i].first;
                
                std::vector<int>::iterator winnerPos = std::find(mainChain.begin(), mainChain.end(), winner);
                std::vector<int>::iterator insertPos = binarySearchInsert(mainChain.begin(), winnerPos, loser);
                mainChain.insert(insertPos, loser);
            }
        }

        // Insert straggler if exists
        if (hasStraggler) {
            std::vector<int>::iterator insertPos = binarySearchInsert(mainChain.begin(), mainChain.end(), straggler);
            mainChain.insert(insertPos, straggler);
        }

        vec = mainChain;
    }

    void fordJohnsonDeque(std::deque<int>& deq) {
        if (deq.size() <= 1) return;

        // Handle pairs and odd element
        std::vector<std::pair<int, int> > pairs;
        int straggler = -1;
        bool hasStraggler = false;

        // Create pairs, ensuring first element of pair is larger
        for (size_t i = 0; i + 1 < deq.size(); i += 2) {
            if (deq[i] > deq[i + 1]) {
                pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
            } else {
                pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
            }
        }

        // Handle odd element
        if (deq.size() % 2 == 1) {
            straggler = deq.back();
            hasStraggler = true;
        }

        if (pairs.empty()) {
            return; // Only one element, already sorted
        }

        // Extract winners for recursive sorting
        std::deque<int> winners;
        for (size_t i = 0; i < pairs.size(); ++i) {
            winners.push_back(pairs[i].first);
        }

        // Recursively sort winners
        fordJohnsonDeque(winners);

        // Build main chain starting with winners
        std::deque<int> mainChain = winners;

        // Insert the first loser at the beginning
        mainChain.insert(mainChain.begin(), pairs[0].second);

        // Generate Jacobsthal sequence
        std::vector<size_t> jacobSeq = generateJacobsthalSeq(pairs.size());

        // Keep track of inserted losers
        std::vector<bool> inserted(pairs.size(), false);
        inserted[0] = true;

        // Insert remaining losers using Jacobsthal sequence
        for (size_t seqIdx = 0; seqIdx < jacobSeq.size(); ++seqIdx) {
            size_t jacobNum = jacobSeq[seqIdx];
            size_t prevJacobNum = (seqIdx == 0) ? 1 : jacobSeq[seqIdx - 1];

            for (size_t idx = std::min(jacobNum, pairs.size()); idx > prevJacobNum; --idx) {
                size_t loserIdx = idx - 1;
                
                if (loserIdx < pairs.size() && !inserted[loserIdx]) {
                    int loser = pairs[loserIdx].second;
                    int winner = pairs[loserIdx].first;

                    std::deque<int>::iterator winnerPos = std::find(mainChain.begin(), mainChain.end(), winner);
                    std::deque<int>::iterator insertPos = binarySearchInsert(mainChain.begin(), winnerPos, loser);
                    mainChain.insert(insertPos, loser);
                    
                    inserted[loserIdx] = true;
                }
            }
        }

        // Insert any remaining uninserted losers
        for (size_t i = 1; i < pairs.size(); ++i) {
            if (!inserted[i]) {
                int loser = pairs[i].second;
                int winner = pairs[i].first;
                
                std::deque<int>::iterator winnerPos = std::find(mainChain.begin(), mainChain.end(), winner);
                std::deque<int>::iterator insertPos = binarySearchInsert(mainChain.begin(), winnerPos, loser);
                mainChain.insert(insertPos, loser);
            }
        }

        // Insert straggler if exists
        if (hasStraggler) {
            std::deque<int>::iterator insertPos = binarySearchInsert(mainChain.begin(), mainChain.end(), straggler);
            mainChain.insert(insertPos, straggler);
        }

        deq = mainChain;
    }

public:
    bool parseInput(int argc, char** argv) {
        if (argc < 2) {
            std::cerr << "Error" << std::endl;
            return false;
        }

        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];

            if (arg.empty() || arg[0] == '-') {
                std::cerr << "Error" << std::endl;
                return false;
            }

            for (size_t j = 0; j < arg.length(); ++j) {
                if (!std::isdigit(arg[j])) {
                    std::cerr << "Error" << std::endl;
                    return false;
                }
            }

            if (arg.length() > 1 && arg[0] == '0') {
                std::cerr << "Error" << std::endl;
                return false;
            }

            std::stringstream ss(arg);
            long num_long;
            ss >> num_long;

            if (ss.fail() || !ss.eof()) {
                std::cerr << "Error" << std::endl;
                return false;
            }

            if (num_long < 0 || num_long > 2147483647) {
                std::cerr << "Error" << std::endl;
                return false;
            }

            int num = static_cast<int>(num_long);
            _numbers.push_back(num);
        }

        if (_numbers.empty()) {
            std::cerr << "Error" << std::endl;
            return false;
        }

        return true;
    }

    void displaySequence(const std::string& label, const std::vector<int>& vec) const {
        std::cout << label;
        size_t count = 0;
        size_t display_limit = 5;
        size_t truncate_threshold = 10;

        for (size_t i = 0; i < vec.size(); ++i) {
            if (i > 0) std::cout << " ";
            std::cout << vec[i];
            count++;
            if (count >= display_limit && vec.size() > truncate_threshold) {
                std::cout << " [...]";
                break;
            }
        }
        std::cout << std::endl;
    }

    void run() {
        if (_numbers.empty()) return;

        displaySequence("Before: ", _numbers);

        // Sort with std::vector
        std::vector<int> vectorCopy = _numbers;
        double startTimeVector = getCurrentTime();
        fordJohnsonVector(vectorCopy);
        double vectorTime = getCurrentTime() - startTimeVector;

        // Sort with std::deque
        std::deque<int> dequeCopy(_numbers.begin(), _numbers.end());
        double startTimeDeque = getCurrentTime();
        fordJohnsonDeque(dequeCopy);
        double dequeTime = getCurrentTime() - startTimeDeque;

        // Display sorted sequence
        std::vector<int> sortedVector(dequeCopy.begin(), dequeCopy.end());
        displaySequence("After:  ", sortedVector);

        // Display timing information
        std::cout.precision(5);
        std::cout << std::fixed;
        std::cout << "Time to process a range of " << _numbers.size()
                  << " elements with std::vector : " << vectorTime << " us" << std::endl;
        std::cout << "Time to process a range of " << _numbers.size()
                  << " elements with std::deque  : " << dequeTime << " us" << std::endl;
    }
};

int main(int argc, char** argv) {
    PmergeMe pmerge;

    if (!pmerge.parseInput(argc, argv)) {
        return EXIT_FAILURE;
    }

    pmerge.run();
    return 0;
}