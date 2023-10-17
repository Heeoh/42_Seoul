#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "Grade.hpp"

class Bureaucrat;

class Form {
private:
	const std::string	name;
	bool 				isSigned;
	const Grade 		requiredGradeToSign;
	const Grade 		requiredGradeToExecute;

	class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Form: Grade is too high!";
        }
    };

	class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Form: Grade is too low!";
        }
    };

public:
	Form();
	Form(const Form& obj);
	Form& operator= (const Form& obj);
	~Form();

	Form(const std::string name, const int signGrade, const int executeGrade);
	std::string getName() const;
	bool getSignStatus() const;
	int getRequiredGradeToSign() const;
	int getRequiredGradeToExecute() const;
	void beSigned(Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif