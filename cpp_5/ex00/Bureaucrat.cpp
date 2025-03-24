#include "Bureaucrat.h"


Bureaucrat::Bureaucrat(void) : name("default"), grade(150) {
    std::cout << "Bureaucrat default constructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) {
    *this = cpy;
    std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name) {
    std::cout << "Bureaucrat parametrized constructor called\n";

    if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
        this->grade = grade;
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cpy) {

    if (this != &cpy)
        this->grade = cpy.getGrade();

    return *this;

}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b) {

    output << b.getName() << ", bureaucrat grade " << b.getGrade();
    return output;

}

std::string Bureaucrat::getName(void) const {
    return name;
}

int Bureaucrat::getGrade(void) const {
    return grade;
}

void Bureaucrat::incrementGrade(void) {
    if (grade == 1)
        throw Bureaucrat::GradeTooHighException(); //instantiating object of class exception
    else
        grade -=1;
}

void Bureaucrat::decrementGrade(void) {
    if (grade == 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade +=1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}