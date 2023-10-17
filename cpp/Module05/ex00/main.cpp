#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try { // 1
		try { // 2
			Bureaucrat a("AAA", 0);
		} 
		catch  (std::exception & e) {
			std::cout << "try2 : " << e.what() << std::endl;
		}

		try { // 3
			Bureaucrat a("AAA", 151);
		} 
		catch  (std::exception & e) {
			std::cout << "try3 : " << e.what() << std::endl;
		}

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
			std::cout << "try1 : " << e.what() << std::endl;
	}

	std::cout << "finish" << std::endl;
}