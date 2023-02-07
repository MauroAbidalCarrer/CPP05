#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

//constructors and destructors
Form::Form() : name(""), target(""), isSigned(false), _gradeToSign(145),  _gradeToExecute(137){}
Form::Form(const Form& other): name(other.getName()), target(other.getTarget()), isSigned(other.getIsSigned()), _gradeToSign(other.getGradeToSign()),  _gradeToExecute(other.getGradeToExecute())
{
    checkGrade(_gradeToSign);
    checkGrade(_gradeToExecute);
}
Form::Form(int gradeToSign, int gradeToExecute, std::string name, std::string target) : name(name), target(target), isSigned(false), _gradeToSign(gradeToSign),  _gradeToExecute(gradeToExecute)
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
    out << "target: " << form.getTarget() << std::endl;
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
void Form::execute(Bureaucrat const & executor) const
{
    if (executor.getGrade() > _gradeToExecute)
        throw Form::GradeTooLowException();
    if (!isSigned)
        throw Form::NotSignedException();
    executeInternal();
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
std::string Form::getTarget()const
{
    return target;
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
const char* Form::NotSignedException::what() const throw()
{
    return "form not signed\n";    
}