#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern & obj) {
	*this = obj;
}

Intern& Intern::operator=(const Intern & obj) {
	if (this != &obj)
		return *this;
	return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string formName, const std::string target) {
	int type = 0;
	for ( ; type < 3; type++) {
		if (FormTypeString[type] == formName)
			break;
	}

	if (type >= 3) {
		std::cout << "Intern couldn't make " << formName 
				  << " because " << formName << " is invalid form type." << std::endl;
		return NULL;
	}

	AForm *newForm;
	switch (type) {
	case ShrubberyCreation:
		newForm = new ShrubberyCreationForm(target); break;
	case RobotomyRequest:
		newForm = new RobotomyRequestForm(target); break;
	case PresidentialPardon:
		newForm = new PresidentialPardonForm(target); break;
	default:
		newForm = NULL;
	}

	std::cout << "Intern creates " << formName << "." << std::endl;
	return newForm;
} 
