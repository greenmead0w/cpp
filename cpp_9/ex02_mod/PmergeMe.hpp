#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector> //dynamic array container
#include <deque> //double queue container
#include <string>
#include <iostream>
#include <sstream> //string stream
#include <ctime>
#include <algorithm> //sort
#include <cstdlib>

class PmergeMe {
private:
    std::vector<int> vectorData;
    std::deque<int> dequeData;
    
    std::vector<int> generateJacobsthalSequence(size_t size);
    std::vector<size_t> generateInsertionOrder(size_t pendSize);
    size_t binarySearchPosition(const std::vector<int>& main, int value, size_t end);
    std::vector<int> fordJohnsonSortVector(std::vector<int> arr);
    
    size_t binarySearchPositionDeque(const std::deque<int>& main, int value, size_t end);
    std::deque<int> fordJohnsonSortDeque(std::deque<int> arr);
    
    bool parseAndValidate(int argc, char** argv);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();
    
    void sort(int argc, char** argv);
};

#endif