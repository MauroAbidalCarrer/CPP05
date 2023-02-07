#ifndef SCHRUBERRY_HPP
# define SCHRUBERRY_HPP
# include <iostream>
# include <string>
# include "Form.hpp"

class ShrubberyCreationForm : public Form
{
    public:
    //constructors and destructors
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm(std::string name, std::string target);
    ~ShrubberyCreationForm();
    //overloads
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);
    //methods
    void executeInternal() const;
};
#endif