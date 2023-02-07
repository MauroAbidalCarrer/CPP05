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
int	Intern::formFinder(std::string name) const
{
	std::string namesArray[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	for(int i = 0; i < 3; i++)
		if(name == namesArray[i])
			return (i);
	return (-1);
}
Form* Intern::makeForm(std::string formName, std::string formTarget) const
{
    switch (formFinder(formName))
    {
    case 0:
        return new ShrubberyCreationForm(formTarget);
        break;
    case 1:
        return new RobotomyRequestForm(formTarget);
        break;
    case 2:
        return new PresidentialPardonForm(formTarget);
        break;
    default:
        std::cerr << "Error: \"" << formName << "\" form does not exist!" << std::endl;
        return NULL;
        break;
    }
}