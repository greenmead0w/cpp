#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype> //isdigit
#include <exception>

class RPN {

    private:
        std::stack<int> _stack;

        bool isOperator(const std::string &token) const;
        bool isDigit(const std::string &token) const;

    public:
        RPN();                             
        RPN(const RPN &cpy);            
        RPN &operator=(const RPN &cpy); 
        ~RPN();                           

        int evaluate(const std::string &expression);

};

#endif
