#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>

class Bureaucrat;

class Form {
private:
	const std::string	name;
	bool 				isSigned;
	const int 			requiredGradeToSign;
	const int 			requiredGradeToExecute;

	class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade is too high!";
        }
    };

	class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw() {
            return "Grade is too low!";
        }
    };

public:
	Form();
	Form(const Form& obj);
	Form& operator= (const Form& obj);
	~Form();

	Form(const std::string name, const int signGrade, const int executeGrade);
	const std::string getName() const;
	const bool getSignStatus() const;
	const int getRequiredGradeToSign() const;
	const int getRequiredGradeToExecute() const;
	const bool beSigned(Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif