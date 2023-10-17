#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
    : AForm(getNameByType(RobotomyRequest), 72, 45), target("unknown") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
    : AForm(obj.getName(), obj.getRequiredGradeToSign(), obj.getRequiredGradeToExecute()), target(obj.getTarget()) {}

RobotomyRequestForm& RobotomyRequestForm::operator= (const RobotomyRequestForm& obj) {
    if (this != &obj) {
        *this = RobotomyRequestForm(obj);
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) 
    : AForm("Robotomy Request Form", 72, 45), target(target) {}

std::string RobotomyRequestForm::getTarget() const {
    return this->target;
}

bool RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!this->getSignStatus())
		throw AForm::UnsignedFormException();
    if (executor.getGrade() > this->getRequiredGradeToExecute())
		throw AForm::GradeTooLowException();

    int isSuccess = std::rand() % 2;

    std::cout << "Drilling ...." << std::endl;
    if (isSuccess) 
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomization of " << target << " has failed." << std::endl;
    
    return isSuccess;
}