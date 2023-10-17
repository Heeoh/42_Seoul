#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
		std::cout << "\033[0;35m" << "[ constructing ]" << "\033[0m" << std::endl; 
		try {
			Bureaucrat a("AAA", 0);
			Bureaucrat b("BBB", 151);
		} 
		catch (Bureaucrat::GradeTooHighException & e) {
			std::cout << "GradeTooHighError: " << e.what() << std::endl;
		}
		catch (Bureaucrat::GradeTooLowException & e) {
			std::cout << "GradeTooLowError: " << e.what() << std::endl;
		}
		std::cout << std::endl;

		std::cout << "\033[0;35m" << "[ incrementing/decrementing ]" << "\033[0m" << std::endl; 
		Bureaucrat a("AAA", 30);
		Bureaucrat highest("highest", 1);
		Bureaucrat lowest("lowest", 150);

		a.incrementGrade();
		std::cout << a << std::endl;
		a.decrementGrade();
		std::cout << a << std::endl;

		highest.incrementGrade();
		lowest.decrementGrade();
	}
	catch (std::exception & e) {
			std::cout << "AnyError: " << e.what() << std::endl;
	}

	std::cout << "finish" << std::endl;
}