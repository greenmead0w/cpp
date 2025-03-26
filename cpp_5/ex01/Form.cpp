#include "Form.h"


Form::Form(void) : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150) {
    std::cout << "Form default constructor\n";
}

Form::Form(const Form &cpy)
    :   name(cpy.name),
        is_signed(cpy.is_signed),
        grade_to_sign(cpy.grade_to_sign),
        grade_to_execute(cpy.grade_to_execute)
{
    std::cout << "Form copy constructor called\n";
}

Form::Form(std::string name, int signGrade, int execGrade)
    :   name(name),
        is_signed(false),
        grade_to_sign(signGrade),
        grade_to_execute(execGrade)

{
    std::cout << "Form parametrized constructor called\n";

    if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

Form::~Form(void) {
    std::cout << "Form destructor called\n";
}

Form &Form::operator=(const Form &cpy) {

    if (this != &cpy)
        this->is_signed = cpy.is_signed;

    return *this;

}

std::ostream &operator<<(std::ostream &out, const Form &form) {

    out << "formName: " << form.getName();
    out << "isSigned: " << form.getIsSigned();
    out << "gradeToSign: " << form.getGradeToSign();
    out << "gradeToExecute: " << form.getGradeToExecute() << std::endl;
    return out;

}

std::string Form::getName(void) const {
    return name;
}

bool Form::getIsSigned(void) const {
    return is_signed;
}

int Form::getGradeToSign(void) const {
    return grade_to_sign;
}

int Form::getGradeToExecute(void) const {
    return grade_to_execute;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "grade is too low";
}

const char* Form::AlreadySigned::what() const throw() {
    return "form has already been signed";
}

void Form::beSigned(const Bureaucrat &signer){
    if (this->is_signed)
        throw AlreadySigned();
    if (signer.getGrade() <= this->grade_to_sign)
        this->is_signed = true;
    else
        throw GradeTooLowException();
}