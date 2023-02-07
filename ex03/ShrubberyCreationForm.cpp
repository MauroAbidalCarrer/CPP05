#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

//constructors and destructors
ShrubberyCreationForm::ShrubberyCreationForm() : Form(145, 137, "", "") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(145, 137, "ShrubberyCreationForm", target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : Form(other) {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
//overloads
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
    (void)rhs;
    return *this;
}
//methods
void ShrubberyCreationForm::executeInternal() const
{
    std::ofstream dstFile;
    std::string dstFileName = getTarget() + "_shrubbery";
    dstFile.open(dstFileName.c_str(), std::ios::trunc);
    if (dstFile)
    {
        dstFile << 
"               ,@@@@@@@,\n" <<
"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n" <<
"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n" <<
"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n" <<
"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n" <<
"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n" <<
"   `&%\\ ` /%&'    |.|        \\ '|8'\n" <<
"       |o|        | |         | |\n" <<
"       |.|        | |         | |\n" <<
"   \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_\n";
    }
    else
        std::cerr << "could not create " << dstFileName << std::endl;
}