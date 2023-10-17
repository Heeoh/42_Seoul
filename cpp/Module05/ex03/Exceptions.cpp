#include "Bureaucrat.hpp"
#include "AForm.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "grade is too low";
}

const char* AForm::UnsignedFormException::what() const throw() {
	return "the form has not been signed";
}