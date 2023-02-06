#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Form::Form() : name(""), isSigned(false), _gradeToSign(1),  _gradeToExecute(1){}
Form::Form(const Form& other): name(other.getName()), isSigned(other.getIsSigned()), _gradeToSign(other.getGradeToSign()),  _gradeToExecute(other.getGradeToExecute())
{
    checkGrade(_gradeToSign);
    checkGrade(_gradeToExecute);
}
Form::Form(int gradeToSign, int gradeToExecute, std::string name) : name(name), isSigned(false), _gradeToSign(gradeToSign),  _gradeToExecute(gradeToExecute)
{
    checkGrade(_gradeToSign);
    checkGrade(_gradeToExecute);
}
Form::~Form() {}
//overloads
Form& Form::operator=(const Form& other)
{
    isSigned = other.getIsSigned();
    return *this;
}
std::ostream& operator<<(std::ostream &out, const Form& form)
{
    out << "\"" << form.getName() << "\" Form:" << std::endl;
    out << "grade to sign: " << form.getGradeToSign() << std::endl;
    out << "grade to execute: " << form.getGradeToExecute() << std::endl;
    out << "is signed: " << form.getIsSigned() << std::endl;
    return out;
}
//methods
void Form::checkGrade(int grade)
{
    if (grade <= 0)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw Form::GradeTooLowException();
}
void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > _gradeToSign)
        throw Form::GradeTooLowException();
    isSigned = true;
}
//accessors
std::string Form::getName() const
{
    return name;
}
int Form::getGradeToSign() const
{
    return _gradeToSign;
}
int Form::getGradeToExecute() const
{
    return _gradeToExecute;
}
bool Form::getIsSigned() const
{
    return isSigned;
}
//nested classes
const char* Form::GradeTooHighException::what() const throw()
{
    return "grade too high\n";
}
const char* Form::GradeTooLowException::what() const throw()
{
    return "grade too low\n";    
}