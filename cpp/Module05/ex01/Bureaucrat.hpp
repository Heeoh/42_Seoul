#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception> 
# include "Form.hpp"

class Bureaucrat {
private:
	const std::string	name;
	int 				grade;
 
	class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Bureaucrat: Grade is too high!";
        }
    };

	class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Bureaucrat: Grade is too low!";
        }
    };	

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat& operator=(const Bureaucrat& obj);
	~Bureaucrat();

	Bureaucrat(const std::string name, int grade);
	const std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form);

private:
	bool isTooHigh() const;
	bool isTooLow() const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif