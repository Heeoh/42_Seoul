#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("unknown") {}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.getName() + "_copy") {
	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj) {
	if (this != &obj)
		this->grade = obj.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name) {
	this->grade = grade;
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

void Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);

		if (form.getSignStatus())
			std::cout << this->name << " signed " << form.getName() << "." << std::endl;
		else 
			std::cout << this->name << " couldn’t sign " << form.getName() 
			<< " because the document is incomplete." << std::endl;
		}
	catch (std::exception & e) {
		std::cout << this->name << " couldn’t sign " << form.getName() 
			<< " because " << e.what() << "." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}