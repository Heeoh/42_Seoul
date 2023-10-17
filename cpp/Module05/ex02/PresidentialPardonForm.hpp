#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm {
private:
    const std::string target;

public:
    PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	PresidentialPardonForm& operator= (const PresidentialPardonForm& obj);
	~PresidentialPardonForm();

    PresidentialPardonForm(const std::string target);
    std::string getTarget() const;
    virtual bool execute(Bureaucrat const & executor) const;
};

#endif