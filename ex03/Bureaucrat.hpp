#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <exception>
# include <string>
# include "Form.hpp"

class Bureaucrat
{
    private:
    //fields
    int _grade;
    const std::string name;
    void setGrade(int newGrade);

    public:
    //constructors/destructors
    Bureaucrat();
    Bureaucrat(int grade, std::string name);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    //overloads
    Bureaucrat& operator=(const Bureaucrat& other);
    //methods
    void signForm(Form& form) const;
    void executeForm(Form const & form) const;
    //accessors
    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    //nested classes
    class GradeTooHighException : public std::exception
    {
        public:
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
        const char* what() const throw();
    };
};
std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureaucrat);
#endif