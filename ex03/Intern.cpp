#include "Intern.hpp"
#include <iostream>
#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
//constructors and destructors
Intern::Intern()
{
    std::cout << "Default constructor of Intern called." << std::endl;
}
Intern::Intern(const Intern& other) 
{
    (void)other;
}
Intern::~Intern() {}
//overloads
Intern& Intern::operator=(const Intern& rhs)
{
    (void)rhs;
    return *this;
}
//methods
Form* Intern::makeForm(std::string formName, std::string formTarget) const
{
	std::string namesArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    Form* (* formMakers [])(std::string) = {ShrubberyCreationForm::makeForm, RobotomyRequestForm::makeForm, PresidentialPardonForm::makeForm};
	for(int i = 0; i < 3; i++)
		if(formName == namesArray[i])
			return ((*formMakers)(formTarget));
    std::cerr << "could not find make form \"" << formName << "\"" << std::endl;
    return (NULL);
}