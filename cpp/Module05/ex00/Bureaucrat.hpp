#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception> 

class Bureaucrat {
private:
	const std::string	name;
	int 				grade;

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

private:
	void setGrade(int newGrade);
	bool isTooHigh(int grade) const;
	bool isTooLow(int grade) const;

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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif