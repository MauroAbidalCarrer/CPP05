#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testFormWithBureaucrat(Form& form, Bureaucrat bureaucrat)
{
    bureaucrat.signForm(form);
    bureaucrat.executeForm(form);
    std::cout << std::endl;
}

void testForm(std::string title, Form& form)
{
    std::cout << "--------------" << title << " test--------------" << std::endl;
    testFormWithBureaucrat(form, Bureaucrat(4, "Jhon very high grade"));
    testFormWithBureaucrat(form, Bureaucrat(60, "Jack mid grade"));
    testFormWithBureaucrat(form, Bureaucrat(150, "Joe lowest grade"));
}

int main()
{
    RobotomyRequestForm robotomy = RobotomyRequestForm("an intern");
    testForm("RobotomyRequestForm", robotomy);
    ShrubberyCreationForm creation = ShrubberyCreationForm("superGardenForm");
    testForm("ShrubberyCreationForm", creation);
    PresidentialPardonForm pardon = PresidentialPardonForm("the same intern");
    testForm("PresidentialPardonForm", pardon);
}