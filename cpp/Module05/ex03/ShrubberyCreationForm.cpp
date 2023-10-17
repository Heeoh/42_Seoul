#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", 145, 137), target("unknown")  {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
    : AForm(obj.getName(), obj.getRequiredGradeToSign(), obj.getRequiredGradeToExecute()), target(obj.getTarget()) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& obj) {
    if (this != &obj) {
        *this = ShrubberyCreationForm(obj);
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
    : AForm("Shrubbery Creation Form", 145, 137), target(target) {}

std::string ShrubberyCreationForm::getTarget() const {
    return this->target;
}

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->getSignStatus())
		throw AForm::UnsignedFormException();
    if (executor.getGrade() > this->getRequiredGradeToExecute())
		throw AForm::GradeTooLowException();
    
    std::string shrubbery = "               ,@@@@@@@,                 "
                            "       ,,,.   ,@@@@@@/@@,  .oo8888o.     "
                            "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o     "
                            "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'    "
                            "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'    "
                            "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'     "
                            "  `&%\\ ` /%&'    |.|        \\ '|8'       "
                            "      |o|        | |         | |         "
                            "      |.|        | |         | |         "
                            " __\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_ ";

    std::ofstream file(target + "_shrubbery");
	
    if (file.is_open())
		throw std::ios_base::failure("Failed to open " + target + "_shrubbery");

    file << shrubbery;
    file.close();

    return true;
}

