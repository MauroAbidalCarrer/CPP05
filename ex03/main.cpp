#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void testFormWithBureaucrat(Form& form, Bureaucrat bureaucrat)
{
    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
    std::cout << std::endl;
}

void testForm(std::string formName, std::string targetName)
{
    Intern intern;
    Form* form = intern.makeForm(formName, targetName);
    if (form == NULL)
        return ;
    std::cout << "--------------" << formName << " test--------------" << std::endl;
    testFormWithBureaucrat(*form, Bureaucrat(4, "Jhon very high grade"));
    testFormWithBureaucrat(*form, Bureaucrat(60, "Jack mid grade"));
    testFormWithBureaucrat(*form, Bureaucrat(150, "Joe lowest grade"));
    delete form;
}

int main()
{
    testForm("robotomy request", "an intern");
    testForm("shrubbery creation", "superGardenForm");
    testForm("presidential pardon", "the same intern");
    testForm("invalid form name", "the same intern");
}