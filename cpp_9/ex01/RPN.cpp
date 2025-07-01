
#include "RPN.hpp"


RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN &cpy) : _stack(cpy._stack) {
}

RPN& RPN::operator=(const RPN &cpy) {
    if (this != &cpy)
        this->_stack = cpy._stack;
    return *this;
}

bool RPN::isOperator(const std::string &token) const {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

bool RPN::isDigit(const std::string &token) const {
    return token.length() == 1 && std::isdigit(token[0]);
}

int RPN::evaluate(const std::string& expression) {
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (isDigit(token))
            _stack.push(token[0] - '0');
        else if (isOperator(token)) 
        {
            if (_stack.size() < 2) {
                throw std::runtime_error("Error");
            }
            int b, a;
            b = _stack.top();
            _stack.pop();
            a = _stack.top(); 
            _stack.pop();

            if (token == "+")
                 _stack.push(a + b);
            else if (token == "-") 
                _stack.push(a - b);
            else if (token == "*") 
                _stack.push(a * b);
            else if (token == "/") 
            {
                if (b == 0)
                    throw std::runtime_error("Error");
                _stack.push(a / b);
            }
        } 
        else
            throw std::runtime_error("Error");
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}
