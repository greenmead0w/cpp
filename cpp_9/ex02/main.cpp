#include "PmergeMe.hpp"

int main(int argc, char** argv) {
    PmergeMe pmerge;

    if (!pmerge.parseInput(argc, argv)) {
        // Error message is printed inside parseInput
        return EXIT_FAILURE;
    }

    pmerge.run();
    return 0;
}