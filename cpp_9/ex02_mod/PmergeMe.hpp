#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <cstdlib>

class PmergeMe {
private:
    std::vector<int> vectorData;
    std::deque<int> dequeData;
    
    // Helper functions for vector
    std::vector<int> generateJacobsthalSequence(size_t size);
    std::vector<size_t> generateInsertionOrder(size_t pendSize);
    size_t binarySearchPosition(const std::vector<int>& main, int value, size_t end);
    std::vector<int> fordJohnsonSortVector(std::vector<int> arr);
    
    // Helper functions for deque
    size_t binarySearchPositionDeque(const std::deque<int>& main, int value, size_t end);
    std::deque<int> fordJohnsonSortDeque(std::deque<int> arr);
    
    bool parseAndValidate(int argc, char** argv);

public:
    // Orthodox Canonical Form
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    // Public interface
    void sort(int argc, char** argv);
};

#endif
