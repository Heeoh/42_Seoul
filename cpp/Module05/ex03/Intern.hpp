#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>

class AForm;

class Intern {
public:
    Intern();
    Intern(const Intern & obj);
    Intern& operator=(const Intern & obj);
    ~Intern();

    AForm* makeForm(const std::string formName, const std::string target);
};

#endif