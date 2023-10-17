#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("unknown"), isSigned(false) {}

Form::Form(const Form& obj) 
		: name(obj.getName() + "_copy"), isSigned(obj.getSignStatus()), 
		  requiredGradeToSign(obj.getRequiredGradeToSign()), 
		  requiredGradeToExecute(obj.getRequiredGradeToExecute()) {}

Form& Form::operator= (const Form& obj) {
	if (this != &obj)
		this->isSigned = obj.getSignStatus();
	return *this;
}

Form::~Form() {}

Form::Form(const std::string name, const int signGrade, const int executeGrade)
		: name(name), isSigned(false), 
		  requiredGradeToSign(signGrade), 
		  requiredGradeToExecute(executeGrade)
{
	if (this->requiredGradeToSign.isTooHigh() 
		|| this->requiredGradeToExecute.isTooHigh())
		throw Form::GradeTooHighException();
	if  (this->requiredGradeToSign.isTooLow() 
		|| this->requiredGradeToExecute.isTooLow())
		throw Form::GradeTooLowException();
}

std::string Form::getName() const {
	return this->name;
}

bool Form::getSignStatus() const {
	return this->isSigned;
}

int Form::getRequiredGradeToSign() const {
	return this->requiredGradeToSign.getGrade();
}

int Form::getRequiredGradeToExecute() const {
	return this->requiredGradeToExecute.getGrade();
}

void Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->requiredGradeToSign.getGrade())
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << obj.getName() << ", " << (obj.getSignStatus() ? "signed, " : "not signed, ")
		<< "required grade to sign: " << obj.getRequiredGradeToSign() 
		<< ", required grade to execute: " << obj.getRequiredGradeToExecute();
	return os;
}