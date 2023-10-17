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

public:
	class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

	class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif