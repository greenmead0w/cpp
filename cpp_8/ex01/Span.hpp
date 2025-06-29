#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iterator> //for std::distance
#include <exception>


class Span {
    private:
        unsigned int max_len;
        std::vector<int> data;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &cpy);
        ~Span();
        Span& operator=(const Span &cpy);

        void addNumber(int num);
        int shortestSpan() const;
        int longestSpan() const;

        template<typename InputIterator>
        void addRange(InputIterator begin, InputIterator end) {
            if (static_cast<unsigned int>(std::distance(begin, end)) + data.size() > max_len)
                throw std::runtime_error("Not enough space to add the range.");
            data.insert(data.end(), begin, end);
}

};


#endif