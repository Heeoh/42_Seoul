#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
	try {
        try { // 2
			Form a("AAA", 0, 0);
		} 
		catch  (std::exception & e) {
			std::cout << "try2: " << e.what() << std::endl;
		}

		try { // 3
			Form a("AAA", 151, 151);
		} 
		catch  (std::exception & e) {
			std::cout << "try3: " << e.what() << std::endl;
		}

        Bureaucrat a = Bureaucrat("AAA", 30);
        Form form1 = Form("Form1", 50, 50);
        Form form2 = Form("Form2", 29, 29);

        std::cout << a << std::endl;
        std::cout << form1 << std::endl;
        std::cout << form2 << std::endl;

        a.signForm(form1);
        std::cout << form1 << std::endl;
        
        // a.signForm(form2);

        a.incrementGrade();
        std::cout << a << std::endl;
        
        a.signForm(form2);
        std::cout << form2 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}