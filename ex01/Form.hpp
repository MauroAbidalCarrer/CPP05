#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
    private:
    const std::string name;
    bool isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    void checkGrade(int grade);
    void setGradeToSign(int newGrade);
    void setGradeToExecute(int newGrade);

    public:
    //constructors and destructors
    Form();
    Form(const Form& other);
    ~Form();
    Form(int gradeToSign, int gradeToExecute, std::string name);
    //overloads
    Form& operator=(const Form& rhs);
    //methods
    void beSigned(const Bureaucrat& bureaucrat);
    //accessors
    std::string getName() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    bool getIsSigned() const;

    //nested classes
    class GradeTooHighException : public std::exception
    {
        public :
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public :
        const char* what() const throw();
    };
};
std::ostream& operator<<(std::ostream &out, const Form& bureaucrat);
#endif