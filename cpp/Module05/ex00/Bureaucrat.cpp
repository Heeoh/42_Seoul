#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("unknown") {
	this->setGrade(150);
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.getName() + "_copy") {
	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this != &obj)
		this->setGrade(obj.getGrade());
	return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	this->setGrade(grade);
}

const std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade;
}

void Bureaucrat::incrementGrade() {
	this->setGrade(this->grade - 1);
}

void Bureaucrat::decrementGrade() {
	this->setGrade(this->grade + 1);
}

void Bureaucrat::setGrade(int newGrade) {
	if (isTooHigh(newGrade))
		throw Bureaucrat::GradeTooHighException();
	if (isTooLow(newGrade))
		throw Bureaucrat::GradeTooLowException();
	this->grade = newGrade;
}

bool Bureaucrat::isTooHigh(int grade) const {
	return grade < 1;
}

bool Bureaucrat::isTooLow(int grade) const {
	return grade > 150;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
