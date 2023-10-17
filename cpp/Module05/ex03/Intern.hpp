#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class AForm;

class Intern {
public:

    AForm* makeForm(std::string formName, std::string targetOfForm);
};

#endif