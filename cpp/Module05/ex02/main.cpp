#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

	try {
        std::cout << "\033[0;35m" << "[ constructing ]" << "\033[0m" << std::endl; 
        ShrubberyCreationForm form_s = ShrubberyCreationForm("home");
        RobotomyRequestForm form_r = RobotomyRequestForm("toto");
        PresidentialPardonForm form_p = PresidentialPardonForm("BBB");

        std::cout << form_s << std::endl;
        std::cout << form_r << std::endl;
        std::cout << form_p << std::endl;
        std::cout << std::endl;

        std::cout << "\033[0;35m" << "[ unsigned form ]" << "\033[0m" << std::endl;
        {
			Bureaucrat a = Bureaucrat("AAA", 20);
			Bureaucrat b = Bureaucrat("BBB", 5);

            a.executeForm(form_p); // error

			a.signForm(form_p);
            b.executeForm(form_p);
        } 
        std::cout << std::endl;

        std::cout << "\033[0;35m" << "[ signed but not enough grade ]" << "\033[0m" << std::endl; 
        {
            Bureaucrat a = Bureaucrat("AAA", 140);
			Bureaucrat b = Bureaucrat("BBB", 100);

			a.signForm(form_s);
            a.executeForm(form_s); // error

			b.executeForm(form_s);
        } 
        std::cout << std::endl;

        std::cout << "\033[0;35m" << "[ random execute of RobotomyRequestForm ]" << "\033[0m" << std::endl; 
        {
            Bureaucrat a = Bureaucrat("AAA", 30);

            a.signForm(form_r);
            a.executeForm(form_r);
        } 

    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}