#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.h"

class Form;

class Bureaucrat {
    private:
        const std::string name;
        int grade;
    public:
        Bureaucrat(void);//default constructor
        Bureaucrat(const Bureaucrat &cpy);//copy constructor
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat(void); //destructor
        Bureaucrat &operator=(const Bureaucrat &cpy);//copy assignment operator

        std::string getName(void) const;
        int getGrade(void) const;
        void incrementGrade(void);
        void decrementGrade(void);

        //ex01
        void signForm(Form &form);

        //ex02
        void			executeForm(const AForm &form);	

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw(); //this is virtual in std::exception base class

        };
        
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();

        };


};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b);

#endif