#include "AForm.h"


AForm::AForm(void) : name("default"), is_signed(false), grade_to_sign(150), grade_to_execute(150) {
    std::cout << "AForm default constructor\n";
}

AForm::AForm(const AForm &cpy)
    :   name(cpy.name),
        is_signed(cpy.is_signed),
        grade_to_sign(cpy.grade_to_sign),
        grade_to_execute(cpy.grade_to_execute)
{
    std::cout << "AForm copy constructor called\n";
}

AForm::AForm(std::string name, int signGrade, int execGrade)
    :   name(name),
        is_signed(false),
        grade_to_sign(signGrade),
        grade_to_execute(execGrade)

{
    std::cout << "AForm parametrized constructor called\n";

    if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm(void) {
    std::cout << "AForm destructor called\n";
}

AForm &AForm::operator=(const AForm &cpy) {

    if (this != &cpy)
        this->is_signed = cpy.is_signed;

    return *this;

}

std::ostream &operator<<(std::ostream &out, const AForm &form) {

    out << "[FORM NAME]: " << form.getName();
    out << " [IS_SIGNED]: " << form.getIsSigned();
    out << " [GRADE_TO_SIGN]: " << form.getGradeToSign();
    out << " [GRADE_TO_EXECUTE]: " << form.getGradeToExecute();
    return out;

}

std::string AForm::getName(void) const {
    return name;
}

bool AForm::getIsSigned(void) const {
    return is_signed;
}

int AForm::getGradeToSign(void) const {
    return grade_to_sign;
}

int AForm::getGradeToExecute(void) const {
    return grade_to_execute;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "grade is too low";
}

const char* AForm::AlreadySignedException::what() const throw() {
    return "form has already been signed";
}

const char* AForm::UnsignedFormException::what() const throw() {
    return "form has not been signed";
}

void AForm::beSigned(const Bureaucrat &signer){
    if (this->is_signed)
        throw AlreadySignedException();
    if (signer.getGrade() <= this->grade_to_sign)
        this->is_signed = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const {
    if (!this->is_signed)
        throw UnsignedFormException();
    if (executor.getGrade > this->grade_to_execute)
        throw GradeTooLowException();
    this->executeAction();
}