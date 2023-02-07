#ifndef PRESIDENTIAL_PARDON_HPP
# define PRESIDENTIAL_PARDON_HPP
# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{
    public:
    //constructors and destructors
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm(std::string target);
    ~PresidentialPardonForm();
    //overloads
    PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
    //methods
    void executeInternal() const;
    static Form* makeForm(std::string target);
};
#endif