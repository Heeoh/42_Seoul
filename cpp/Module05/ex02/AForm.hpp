#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include "Grade.hpp"

class Bureaucrat;

class AForm {
private:
	const std::string	name;
	bool 				isSigned;
	const Grade 		requiredGradeToSign;
	const Grade 		requiredGradeToExecute;

protected:
	class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "grade is too high";
        }
    };

	class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "grade is too low";
        }
    };

	class UnsignedFormException : public std::exception {
	public:
        const char* what() const throw() {
            return "the form has not been signed";
        }
	};

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

};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif