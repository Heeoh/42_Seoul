#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
		: name(""), isSigned(false), 
		  requiredGradeToSign(150), requiredGradeToExecute(150) {}

Form::Form(const Form& obj) 
		: name(obj.getName()), isSigned(obj.getSignStatus()), 
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
		  requiredGradeToExecute(executeGrade) {}

const std::string Form::getName() const {
	return this->name;
}

const bool Form::getSignStatus() const {
	return this->isSigned;
}

const int Form::getRequiredGradeToSign() const {
	return this->requiredGradeToSign;
}

const int Form::getRequiredGradeToExecute() const {
	return this->requiredGradeToExecute;
}

const bool Form::beSigned(Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->requiredGradeToSign)
		throw Form::GradeTooLowException();
	this->isSigned = true;
}
