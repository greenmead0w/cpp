
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.h"

class Bureaucrat; //to avoid circular dependency ("form needing bureaucrat and viceversa")

class AForm {

    private:
        const std::string name;
        bool is_signed;
        const int grade_to_sign;
        const int grade_to_execute;

    public:
        AForm(void);
        AForm(const AForm &cpy);
        AForm(std::string name, int signGrade, int execGrade);
        virtual ~AForm(void);
        AForm &operator=(const AForm &cpy);

        void beSigned(const Bureaucrat &signer);

        //ex02
        void    execute(const Bureaucrat &executor) const;
        virtual void    executeAction() const = 0;
        
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

        class AlreadySignedException : public std::exception {
            public:
                const char* what() const throw();

        };

        class UnsignedFormException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif