#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Grade.hpp"

class Bureaucrat;

typedef enum FormType {
	ShrubberyCreation = 0,
	RobotomyRequest,
	PresidentialPardon,
	Unknown
} FormType;

static const std::string FormTypeString[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

class AForm {
private:
	const std::string	name;
	bool 				isSigned;
	const Grade 		requiredGradeToSign;
	const Grade 		requiredGradeToExecute;

public:
	AForm();
	AForm(const AForm& obj);
	AForm& operator= (const AForm& obj);
	virtual ~AForm();

	AForm(const std::string name, const int signGrade, const int executeGrade);
	std::string getName() const;
	bool getSignStatus() const;
	int getRequiredGradeToSign() const;
	int getRequiredGradeToExecute() const;
	void beSigned(Bureaucrat const & bureaucrat);
	virtual bool execute(Bureaucrat const & executor) const = 0;

protected:
	bool isExecutableBy(Bureaucrat const & executor) const;

public:
	class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

	class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

	class UnsignedFormException : public std::exception {
	public:
        const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);


#endif