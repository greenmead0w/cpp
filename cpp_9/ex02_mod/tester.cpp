#include "PmergeMe.hpp"
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>

// ANSI color codes
#define COLOR_RED "\033[1;31m"
#define COLOR_GREEN "\033[1;32m"
#define COLOR_YELLOW "\033[1;33m"
#define COLOR_BLUE "\033[1;34m"
#define COLOR_RESET "\033[0m"

class Tester {
private:
    int testsPassed;
    int testsFailed;
    
    // Helper function to print a vector
    void printVector(const std::vector<int>& vec) {
        std::cout << "[ ";
        for (size_t i = 0; i < vec.size(); i++) {
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << " ";
            }
        }
        std::cout << " ]";
    }
    
    // Helper function to convert vector to argc/argv format
    char** vectorToArgv(const std::vector<int>& vec, int& argc) {
        argc = vec.size() + 1;
        char** argv = new char*[argc];
        argv[0] = new char[10];
        std::strcpy(argv[0], "./PmergeMe");
        
        for (size_t i = 0; i < vec.size(); i++) {
            std::stringstream ss;
            ss << vec[i];
            std::string str = ss.str();
            argv[i + 1] = new char[str.length() + 1];
            std::strcpy(argv[i + 1], str.c_str());
        }
        
        return argv;
    }
    
    // Helper function to free argv
    void freeArgv(char** argv, int argc) {
        for (int i = 0; i < argc; i++) {
            delete[] argv[i];
        }
        delete[] argv;
    }
    
    // Get sorted result from PmergeMe
    std::vector<int> getPmergeMeResult(const std::vector<int>& input) {
        // Redirect cout to suppress output
        std::streambuf* oldCoutBuffer = std::cout.rdbuf();
        std::ostringstream nullStream;
        std::cout.rdbuf(nullStream.rdbuf());
        
        int argc;
        char** argv = vectorToArgv(input, argc);
        
        PmergeMe sorter;
        sorter.sort(argc, argv);
        
        freeArgv(argv, argc);
        
        // Restore cout
        std::cout.rdbuf(oldCoutBuffer);
        
        // Parse the output to get the result
        std::string output = nullStream.str();
        std::vector<int> result;
        
        // Find "After: " line and parse numbers
        size_t afterPos = output.find("After: ");
        if (afterPos != std::string::npos) {
            afterPos += 7; // Skip "After: "
            std::istringstream iss(output.substr(afterPos));
            int num;
            while (iss >> num) {
                result.push_back(num);
            }
        }
        
        return result;
    }
    
    // Compare two vectors
    bool vectorsEqual(const std::vector<int>& v1, const std::vector<int>& v2) {
        if (v1.size() != v2.size()) {
            return false;
        }
        for (size_t i = 0; i < v1.size(); i++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }
        return true;
    }
    
    // Run a single test
    void runTest(const std::vector<int>& input, const std::string& testName) {
        std::cout << COLOR_BLUE << "========================================" << COLOR_RESET << std::endl;
        std::cout << COLOR_YELLOW << "Test: " << testName << COLOR_RESET << std::endl;
        std::cout << "Size: " << input.size() << " elements" << std::endl;
        std::cout << std::endl;
        
        // Print raw input
        std::cout << "Raw Input:     ";
        printVector(input);
        std::cout << std::endl;
        
        // Get expected result using std::sort
        std::vector<int> expected = input;
        std::sort(expected.begin(), expected.end());
        std::cout << "Expected Sort: ";
        printVector(expected);
        std::cout << std::endl;
        
        // Get PmergeMe result
        std::vector<int> result = getPmergeMeResult(input);
        std::cout << "PmergeMe Sort: ";
        printVector(result);
        std::cout << std::endl;
        
        // Compare results
        std::cout << std::endl;
        if (vectorsEqual(expected, result)) {
            std::cout << COLOR_GREEN << "✓ PASS - Results match!" << COLOR_RESET << std::endl;
            testsPassed++;
        } else {
            std::cout << COLOR_RED << "✗ FAIL - Results differ!" << COLOR_RESET << std::endl;
            testsFailed++;
        }
        std::cout << std::endl;
    }
    
    // Generate random vector
    std::vector<int> generateRandomVector(size_t size, int minVal = 0, int maxVal = 10000) {
        std::vector<int> vec;
        for (size_t i = 0; i < size; i++) {
            vec.push_back(minVal + std::rand() % (maxVal - minVal + 1));
        }
        return vec;
    }

public:
    Tester() : testsPassed(0), testsFailed(0) {
        std::srand(std::time(0));
    }
    
    void runAllTests() {
        std::cout << COLOR_BLUE << "========================================" << COLOR_RESET << std::endl;
        std::cout << COLOR_BLUE << "   PMERGEME ALGORITHM ACCURACY TESTER   " << COLOR_RESET << std::endl;
        std::cout << COLOR_BLUE << "========================================" << COLOR_RESET << std::endl;
        std::cout << std::endl;
        
        // Edge cases
        std::vector<int> empty;
        runTest(empty, "Empty array");
        
        std::vector<int> single;
        single.push_back(42);
        runTest(single, "Single element");
        
        std::vector<int> twoElements;
        twoElements.push_back(5);
        twoElements.push_back(3);
        runTest(twoElements, "Two elements");
        
        // Small sizes (focus area)
        std::vector<int> three;
        three.push_back(9);
        three.push_back(2);
        three.push_back(5);
        runTest(three, "Three elements");
        
        std::vector<int> four;
        four.push_back(7);
        four.push_back(3);
        four.push_back(9);
        four.push_back(1);
        runTest(four, "Four elements");
        
        std::vector<int> five;
        five.push_back(3);
        five.push_back(5);
        five.push_back(9);
        five.push_back(7);
        five.push_back(4);
        runTest(five, "Five elements (subject example)");
        
        // Random tests for sizes 6-19
        for (int size = 6; size <= 19; size++) {
            std::stringstream ss;
            ss << "Random " << size << " elements";
            runTest(generateRandomVector(size, 0, 100), ss.str());
        }
        
        // Test with duplicates
        std::vector<int> duplicates;
        duplicates.push_back(5);
        duplicates.push_back(3);
        duplicates.push_back(5);
        duplicates.push_back(1);
        duplicates.push_back(3);
        duplicates.push_back(5);
        runTest(duplicates, "With duplicates");
        
        // Test already sorted
        std::vector<int> sorted;
        for (int i = 1; i <= 10; i++) {
            sorted.push_back(i);
        }
        runTest(sorted, "Already sorted (10 elements)");
        
        // Test reverse sorted
        std::vector<int> reverseSorted;
        for (int i = 10; i >= 1; i--) {
            reverseSorted.push_back(i);
        }
        runTest(reverseSorted, "Reverse sorted (10 elements)");
        
        // Test all same values
        std::vector<int> allSame;
        for (int i = 0; i < 8; i++) {
            allSame.push_back(7);
        }
        runTest(allSame, "All same values (8 elements)");
        
        // Larger sizes
        runTest(generateRandomVector(20, 0, 1000), "Random 20 elements");
        runTest(generateRandomVector(50, 0, 1000), "Random 50 elements");
        runTest(generateRandomVector(100, 0, 10000), "Random 100 elements");
        runTest(generateRandomVector(500, 0, 10000), "Random 500 elements");
        runTest(generateRandomVector(1000, 0, 100000), "Random 1000 elements");
        runTest(generateRandomVector(3000, 0, 100000), "Random 3000 elements");
        
        // Final summary
        std::cout << COLOR_BLUE << "========================================" << COLOR_RESET << std::endl;
        std::cout << COLOR_BLUE << "           TEST SUMMARY                 " << COLOR_RESET << std::endl;
        std::cout << COLOR_BLUE << "========================================" << COLOR_RESET << std::endl;
        std::cout << COLOR_GREEN << "Passed: " << testsPassed << COLOR_RESET << std::endl;
        std::cout << COLOR_RED << "Failed: " << testsFailed << COLOR_RESET << std::endl;
        std::cout << "Total:  " << (testsPassed + testsFailed) << std::endl;
        std::cout << std::endl;
        
        if (testsFailed == 0) {
            std::cout << COLOR_GREEN << "🎉 ALL TESTS PASSED! 🎉" << COLOR_RESET << std::endl;
        } else {
            std::cout << COLOR_RED << "⚠ SOME TESTS FAILED ⚠" << COLOR_RESET << std::endl;
        }
        std::cout << COLOR_BLUE << "========================================" << COLOR_RESET << std::endl;
    }
};

int main() {
    Tester tester;
    tester.runAllTests();
    return 0;
}
