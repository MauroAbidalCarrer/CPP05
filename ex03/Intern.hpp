#ifndef INTERN_HPP
# define INTERN_HPP
# include <iostream>
# include <string>
# include "Form.hpp"

class Intern
{
    private:
    int	formFinder(std::string name) const;
    public:
    //constructors and destructors
    Intern();
    Intern(const Intern& other);
    ~Intern();
    //overloads
    Intern& operator=(const Intern& rhs);
    //methods
    Form* makeForm(std::string formName, std::string formTarget) const;
};
#endif