#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
    private:
    const std::string name;
    const std::string target;
    bool isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;
    void checkGrade(int grade);
    
    protected:
    virtual void executeInternal() const = 0;

    public:
    //constructors and destructors
    Form();
    Form(const Form& other);
    ~Form();
    Form(int gradeToSign, int gradeToExecute, std::string name, std::string target);
    //overloads
    Form& operator=(const Form& rhs);
    //methods
    void beSigned(const Bureaucrat& bureaucrat);
    void execute(Bureaucrat const & executor) const;
    //accessors
    std::string getName() const;
    std::string getTarget()const;
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
    class NotSignedException : public std::exception
    {
        public :
        const char* what() const throw();
    };
};
std::ostream& operator<<(std::ostream &out, const Form& bureaucrat);
#endif