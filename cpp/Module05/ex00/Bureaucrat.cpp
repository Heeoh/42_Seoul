#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() 
			: name(""), grade(150) {}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) 
			: name(obj.getName()), grade(obj.getGrade()) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this != &obj)
		this->grade = obj.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) 
			: name(name), grade(grade) {
	if (isTooHigh())
		throw Bureaucrat::GradeTooHighException();
	if (isTooLow())
		throw Bureaucrat::GradeTooLowException();
}

const std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
	this->grade--; 	
	if (isTooHigh())
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	this->grade ++;
	if (isTooLow())
		throw Bureaucrat::GradeTooLowException();
}

bool Bureaucrat::isTooHigh() const {
	return this->grade < 1;
}

bool Bureaucrat::isTooLow() const {
	return this->grade > 150;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}