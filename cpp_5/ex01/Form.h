
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.h"

class Bureaucrat; //to avoid circular dependency ("form needing bureaucrat and viceversa")

class Form {

    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;

    public:
        Form(void);
        Form(const Form &cpy);
        Form(std::string name, int signGrade, int execGrade);
        ~Form(void);
        Form &operator=(const Form &cpy);

        void beSigned(const Bureaucrat &signer);
        
        //getters
        std::string getName(void) const;
        bool getIsSigned(void) const;
        int getGradeToSign(void) const;
        int getGradeToExecute(void) const;
    
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();

        };
        
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();

        };

        class AlreadySigned : public std::exception {
            public:
                const char* what() const throw();

        };
};

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif