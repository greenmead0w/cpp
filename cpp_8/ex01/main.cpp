
#include "Span.hpp"
#include <vector>//for main 2

int main() 
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0; 
}

// int main() {
//         Span sp(10);

//         std::vector<int> nums;
//         nums.push_back(5);
//         nums.push_back(3);
//         nums.push_back(17);
//         nums.push_back(9);
//         nums.push_back(11);

//         // Test addRange with vector iterators
//         sp.addRange(nums.begin(), nums.end());

//         std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
//         std::cout << "Longest span: " << sp.longestSpan() << std::endl;

//     return 0;
// }
