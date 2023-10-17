#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
		: name(""), isSigned(false), 
		  requiredGradeToSign(Grade()), requiredGradeToExecute(Grade()) {}

AForm::AForm(const AForm& obj) 
		: name(obj.getName()), isSigned(obj.getSignStatus()), 
		  requiredGradeToSign(obj.getRequiredGradeToSign()), 
		  requiredGradeToExecute(obj.getRequiredGradeToExecute()) {
	if (this->requiredGradeToSign.isTooHigh() 
		|| this->requiredGradeToExecute.isTooHigh())
		throw AForm::GradeTooHighException();
	if  (this->requiredGradeToSign.isTooLow() 
		|| this->requiredGradeToExecute.isTooLow())
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator= (const AForm& obj) {
	if (this != &obj) {
		this->isSigned = obj.getSignStatus();
	}
	return *this;
}

AForm::~AForm() {}

AForm::AForm(const std::string name, const int signGrade, const int executeGrade)
		: name(name), isSigned(false), 
		  requiredGradeToSign(signGrade), 
		  requiredGradeToExecute(executeGrade)
{
	if (this->requiredGradeToSign.isTooHigh() 
		|| this->requiredGradeToExecute.isTooHigh())
		throw AForm::GradeTooHighException();
	if  (this->requiredGradeToSign.isTooLow() 
		|| this->requiredGradeToExecute.isTooLow())
		throw AForm::GradeTooLowException();
}

std::string AForm::getName() const {
	return this->name;
}

bool AForm::getSignStatus() const {
	return this->isSigned;
}


int AForm::getRequiredGradeToSign() const {
	return this->requiredGradeToSign.getGrade();
}

int AForm::getRequiredGradeToExecute() const {
	return this->requiredGradeToExecute.getGrade();
}

void AForm::beSigned(Bureaucrat const & bureaucrat) {
	if (bureaucrat.getGrade() > this->getRequiredGradeToSign())
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << obj.getName() << ", " << (obj.getSignStatus() ? "signed, " : "not signed, ")
		<< "required grade to sign: " << obj.getRequiredGradeToSign() 
		<< ", required grade to execute: " << obj.getRequiredGradeToExecute();
	return os;
}