#include "Bureaucrat.hpp"
#include "Form.hpp"

void testFormCannon()
{
    std::cout << "---------------testing form cannonic... form---------------" << std::endl;
    Form defaultForm;
    std::cout << "Debugging defaultForm:" << std::endl;
    std::cout << defaultForm << std::endl;
    Form setForm = Form(123, 22, "awesome form");
    std::cout << "Debugging setForm:" << std::endl;
    std::cout << setForm << std::endl;
    Form copiedForm = Form(setForm);
    std::cout << "Debugging copiedForm(copied from setForm):" << std::endl;
    std::cout << copiedForm << std::endl;
    std::cout << "Assigning default Form to setForm and debugging it:" << std::endl;
    defaultForm = setForm;
    std::cout << defaultForm << std::endl;
    try 
    { 
        std::cout << "Instantiating Form with grade to sign too high:" << std::endl;
        Form tooHigh = Form(0, 123, "tooHigh");
    }
    catch (Form::GradeTooHighException& e)
    {
        std::cout << "Caught GradeTooHighException as expected, Exception.what: " << e.what() << std::endl; 
    }
    try 
    { 
        std::cout << "Instantiating Form with grade to execute too high:" << std::endl;
        Form tooHigh = Form(123, 0, "tooHigh");
    }
    catch (Form::GradeTooHighException& e)
    {
        std::cout << "Caught GradeTooHighException as expected, Exception.what: " << e.what() << std::endl; 
    }
    try 
    {
        std::cout << "Instantiating Form with grade to sign too low:" << std::endl;
        Form tooLow = Form(151, 1, "too low");
    }
    catch (Form::GradeTooLowException& e)
    {
        std::cout << "Caught GradeTooLowException as expected, Exception.what: " << e.what()  << std::endl;
    }
    try 
    {
        std::cout << "Instantiating Form with grade to execute too low:" << std::endl;
        Form tooLow = Form(1, 151, "too low");
    }
    catch (Form::GradeTooLowException& e)
    {
        std::cout << "Caught GradeTooLowException as expected, Exception.what: " << e.what()  << std::endl;
    }
}

void testSigning()
{
    Bureaucrat jhon = Bureaucrat(12, "jhon");
    Form formForJhon = Form(12, 12, "formForJhon");
    jhon.signForm(formForJhon);
    Bureaucrat notJhon = Bureaucrat(14, "bureaucrat lower than Jhon");
    notJhon.signForm(formForJhon);
}

int main()
{
    testFormCannon();
    testSigning();
}