#include "Bureaucrat.hpp"

//constructors/destructors
Bureaucrat::Bureaucrat() : _grade(1), name ("") {}
Bureaucrat::Bureaucrat(int grade, std::string name) : name(name) 
{
    setGrade(grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) 
{
    setGrade(other.getGrade());
}
Bureaucrat::~Bureaucrat() {}
//overloads
std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << '.' << std::endl;
    return out;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    setGrade(other.getGrade());
    return *this;
}
//methods
void Bureaucrat::signForm(Form& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    }
    catch(const Form::GradeTooLowException & e)
    {
        std::cerr << name << ", couldn’t sign " << form.getName() << " beacuse: " << e.what();
    }
}
//accessors
void Bureaucrat::setGrade(int newGrade) 
{
    if (newGrade <= 0)
        throw Bureaucrat::GradeTooHighException();
    if (newGrade > 150)
        throw Bureaucrat::GradeTooLowException();
    _grade = newGrade;
}
void Bureaucrat::incrementGrade() 
{
    setGrade(_grade - 1);
}
void Bureaucrat::decrementGrade() 
{
    setGrade(_grade + 1);
}
std::string Bureaucrat::getName() const
{
    return name;
}
int Bureaucrat::getGrade() const
{
    return _grade;
}
//nested classes
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade too high\n";
}
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade too low\n";    
}