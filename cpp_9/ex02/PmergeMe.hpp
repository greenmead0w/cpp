#ifndef PMERGEME_HPP
#define PMERGEME_HPP

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

        template<typename Iterator>
        Iterator binarySearchInsert(Iterator begin, Iterator end, int value) const {
            Iterator low = begin;
            Iterator high = end;

            while (low < high) {
                // C++98 standard says Iterators are RandomAccessIterator for vector/deque
                // low + (high - low) / 2 is valid for RandomAccessIterator
                Iterator mid = low + (std::distance(low, high) / 2);
                if (*mid < value) {
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            return low; // 'low' is the insertion point where value should be placed at (before)
        }

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

        void fordJohnsonSortVector(std::vector<int>& c);
        void fordJohnsonSortDeque(std::deque<int>& c);
        double getCurrentTime() const;



    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &cpy);
        PmergeMe &operator=(const PmergeMe &cpy);

        bool parseInput(int argc, char** argv);
        void run();

};

#endif