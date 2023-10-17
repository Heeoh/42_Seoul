#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm(getNameByType(PresidentialPardon), 25, 5), target("unknown") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
    : AForm(obj.getName(), obj.getRequiredGradeToSign(), obj.getRequiredGradeToExecute()), target(obj.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& obj) {
    if (this != &obj) {
        *this = PresidentialPardonForm(obj);
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon Form", 25, 5), target(target) {}

std::string PresidentialPardonForm::getTarget() const {
    return this->target;
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->getSignStatus())
		throw AForm::UnsignedFormException();
    if (executor.getGrade() > this->getRequiredGradeToExecute())
		throw AForm::GradeTooLowException();

    std::cout << target << " has been pardoned by Zaphod Beeblebrox.";
    return true;
}

