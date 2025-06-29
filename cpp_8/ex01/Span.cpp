#include "Span.hpp"

Span::Span() : max_len(3) {std::cout << "default constructor called\n";}

Span::Span(unsigned int n) : max_len(n) {std::cout << "parametrized constructor called\n";}

Span::Span(const Span &cpy) : max_len(cpy.max_len), data(cpy.data) {std::cout <<"copy constructor called\n";}

Span::~Span() {std::cout << "destructor called\n";}

Span& Span::operator=(const Span& cpy) 
{
    if (this != &cpy) {
        data = cpy.data;
        max_len = cpy.max_len;
    }
    return *this;
}

void Span::addNumber(int num) 
{
    if (data.size() >= max_len)
        throw std::runtime_error("Span is full.");
    data.push_back(num);
}

int Span::shortestSpan() const 
{
    if (data.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span.");

    std::vector<int> sorted(data);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max(); //start from the highest possible num
    for (size_t i = 0; i < sorted.size() - 1; ++i) {
        int span = sorted[i + 1] - sorted[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (data.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span.");

    int minVal = *std::min_element(data.begin(), data.end()); //algorithmic STL
    int maxVal = *std::max_element(data.begin(), data.end());

    return maxVal - minVal;
}