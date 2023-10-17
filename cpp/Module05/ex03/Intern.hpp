#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>

class AForm;

class Intern {
public:
    Intern();
    Intern(const Intern & obj);
    Intern& operator=(const Intern & obj);
    ~Intern();

    AForm* makeForm(std::string formName, std::string target);
};

#endif