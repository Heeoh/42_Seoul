#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm {
private:
    const std::string target;

public:
    RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	RobotomyRequestForm& operator= (const RobotomyRequestForm& obj);
	~RobotomyRequestForm();

    RobotomyRequestForm(std::string target);
    std::string getTarget() const;
    virtual bool execute(Bureaucrat const & executor) const;
};

#endif