#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <string>

//constructors and destructors
PresidentialPardonForm::PresidentialPardonForm() : Form(25, 5, "", "") {}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(25, 5, "PresidentialPardonForm", target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : Form(other) {}
PresidentialPardonForm::~PresidentialPardonForm() {}
//overloads
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
    (void)rhs;
    return *this;
}
//methods
void PresidentialPardonForm::executeInternal() const
{
    std::cout << getTarget() << " has been forgiven by Zaphod Beeblebrox." << std::endl;
}