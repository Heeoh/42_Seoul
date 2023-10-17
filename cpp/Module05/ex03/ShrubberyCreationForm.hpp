#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
private:
    const std::string target;

public:
    ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	ShrubberyCreationForm& operator= (const ShrubberyCreationForm& obj);
	~ShrubberyCreationForm();

    ShrubberyCreationForm(std::string target);
    std::string getTarget() const;
    virtual bool execute(Bureaucrat const & executor) const;
};

#endif