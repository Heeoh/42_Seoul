#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try { // 1
        std::cout << "\033[0;35m" << "[ Form constructor exception test ]" << "\033[0m" << std::endl; 
        try {
			Form a("AAA", 0, 0);
		} 
		catch  (std::exception & e) {
			std::cout << "Too High Error: " << e.what() << std::endl;
		}

		try {
			Form a("AAA", 151, 151);
		} 
		catch  (std::exception & e) {
			std::cout << "Too Low Error: " << e.what() << std::endl;
		}
       
        std::cout << std::endl;
        std::cout << "\033[0;35m" << "[ signForm() test ]" << "\033[0m" << std::endl; 

        Bureaucrat a = Bureaucrat("AAA", 30);
        Form form = Form("Form", 29, 29);

        std::cout << a << std::endl;
        std::cout << form << std::endl;
        std::cout << std::endl;

        a.signForm(form);  // error, due to low grade
        std::cout << form << std::endl;
        std::cout << std::endl;
        
        a.incrementGrade();
        a.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}