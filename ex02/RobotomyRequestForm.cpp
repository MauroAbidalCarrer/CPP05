#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

//constructors and destructors
RobotomyRequestForm::RobotomyRequestForm() : Form(72, 45, "", "") {}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(72, 45, "RobotomyRequestForm", target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : Form(other) {}
RobotomyRequestForm::~RobotomyRequestForm() {}
//overloads
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
    (void)rhs;
    return *this;
}
//methods
void RobotomyRequestForm::executeInternal() const
{
    std::cout << "*DRILL NOISES*" << std::endl;
    std::srand((unsigned int)time(NULL));
    std::string negation = rand() % 2 != 0 ? "" : "not ";
    std::cout << getTarget() << " has " << negation << "been robotomized" << std::endl;
}