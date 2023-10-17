#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() 
			: name(""), grade(Grade()) {}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) 
			: name(obj.getName()), grade(obj.getGrade()) {
	if (this->grade.isTooHigh())
		throw Bureaucrat::GradeTooHighException();
	if (this->grade.isTooLow())
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this != &obj)
		this->grade = obj.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) 
			: name(name), grade(grade) {
	if (this->grade.isTooHigh())
		throw Bureaucrat::GradeTooHighException();
	if (this->grade.isTooLow())
		throw Bureaucrat::GradeTooLowException();
}

const std::string Bureaucrat::getName() const {
	return this->name;
}

int Bureaucrat::getGrade() const {
	return this->grade.getGrade();
}

void Bureaucrat::incrementGrade() {
	this->grade--;	
	if (this->grade.isTooHigh())
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade() {
	this->grade++;
	if (this->grade.isTooLow())
		throw Bureaucrat::GradeTooLowException();
}

void Bureaucrat::signForm(AForm& form) {
	form.beSigned(*this);

	if (form.getSignStatus())
		std::cout << this->name << " signed " << form.getName() << std::endl;
	else 
		std::cout << this->name << " couldn’t  signed " << form.getName() 
		<< " because the document is incomplete." << std::endl;
}

void Bureaucrat::executeForm(AForm const & form) {
	if (form.execute(*this))
		std::cout << this->name << " executed " << form.getName() << std::endl;
	else 
		std::cout << this->name << " couldn’t execute " << form.getName() 
		<< " due to an unexpected event." << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}