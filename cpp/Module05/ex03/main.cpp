#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

	try {
		Intern someRandomIntern;
		AForm *rrf, *scf, *ppf, *wrong;

		std::cout << "\033[0;35m" << "[ make RobotomyRequestForm ]" << "\033[0m" << std::endl; 
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		std::cout << *rrf << std::endl;
		delete rrf;
		std::cout << std::endl;	

		std::cout << "\033[0;35m" << "[ make ShrubberyCreationForm ]" << "\033[0m" << std::endl; 
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
		std::cout << *scf << std::endl;
		delete scf;
		std::cout << std::endl;		

		std::cout << "\033[0;35m" << "[ make PresidentalPardonForm ]" << "\033[0m" << std::endl; 	
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
		std::cout << *ppf << std::endl;
		delete ppf;
		std::cout << std::endl;	

		std::cout << "\033[0;35m" << "[ make Wrong From ]" << "\033[0m" << std::endl; 	
		wrong = someRandomIntern.makeForm("wrongForm", "Bender");
		if (wrong) {
			std::cout << *wrong << std::endl;
			std::cout << std::endl;	
			delete wrong;
		}
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}