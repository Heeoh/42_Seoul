#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", 25, 5), target("unknown") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
    : AForm(obj.getName() + "_copy", obj.getRequiredGradeToSign(), obj.getRequiredGradeToExecute()), target(obj.getTarget()) {}

PresidentialPardonForm& PresidentialPardonForm::operator= (const PresidentialPardonForm& obj) {
    if (this != &obj) 
        return *this;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("Presidential Pardon Form", 25, 5), target(target) {}

std::string PresidentialPardonForm::getTarget() const {
    return this->target;
}

bool PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->isExecutableBy(executor)) 
		return false;

    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    return true;
}

