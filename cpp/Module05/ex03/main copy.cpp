#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

	try {
        ShrubberyCreationForm form_s = ShrubberyCreationForm("home");
        RobotomyRequestForm form_r = RobotomyRequestForm("toto");
        PresidentialPardonForm form_p = PresidentialPardonForm("BBB");

        std::cout << form_s << std::endl;
        std::cout << form_r << std::endl;
        std::cout << form_p << std::endl;
        std::cout << std::endl;

        try { // unsigned form
            Bureaucrat a = Bureaucrat("AAA", 100);

            a.executeForm(form_s);
        } 
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;

        try { // signed but not enough grade
            Bureaucrat a = Bureaucrat("AAA", 20);

            a.signForm(form_p);
            a.executeForm(form_p);
        } 
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        } 
        std::cout << std::endl;

        try { // random execute
            Bureaucrat a = Bureaucrat("AAA", 30);

            a.signForm(form_r);
            a.executeForm(form_r);
        } 
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}