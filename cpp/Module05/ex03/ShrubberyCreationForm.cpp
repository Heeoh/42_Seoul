#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm(FormTypeString[ShrubberyCreation], 145, 137), target("unknown")  {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
    : AForm(obj.getName() + "_copy", obj.getRequiredGradeToSign(), obj.getRequiredGradeToExecute()), target(obj.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& obj) {
    if (this != &obj) 
		return *this;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm(FormTypeString[ShrubberyCreation], 145, 137), target(target) {}

std::string ShrubberyCreationForm::getTarget() const {
    return this->target;
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->isExecutableBy(executor)) 
		return false;
    
    std::string shrubbery = "               ,@@@@@@@,                 \n"
                            "       ,,,.   ,@@@@@@/@@,  .oo8888o.     \n"
                            "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o     \n"
                            "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'    \n"
                            "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'    \n"
                            "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'     \n"
                            "  `&%\\ ` /%&'    |.|        \\ '|8'       \n"
                            "      |o|        | |         | |         \n"
                            "      |.|        | |         | |         \n"
                            " __\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_ \n";

    std::ofstream file(target + "_shrubbery");
	
    if (!file.is_open())
		throw std::ios_base::failure("Failed to open " + target + "_shrubbery");

    file << shrubbery;
    file.close();

    return true;
}
