#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP
# include <iostream>
# include <string>
# include "Form.hpp"

class RobotomyRequestForm : public Form
{
    public:
    //constructors and destructors
    RobotomyRequestForm();
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm(std::string target);
    ~RobotomyRequestForm();
    //overloads
    RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);
    //methods
    void executeInternal() const;
    static Form* makeForm(std::string target);
};
#endif