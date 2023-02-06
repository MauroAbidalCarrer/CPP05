#include "Bureaucrat.hpp"

void testCannon()
{
    std::cout << "---------------testing cannon---------------" << std::endl;
    Bureaucrat defaultBur;
    std::cout << "Debugging defaultBur:" << std::endl;
    std::cout << defaultBur << std::endl;
    Bureaucrat setBur = Bureaucrat(123, "Jhon");
    std::cout << "Debugging setBur:" << std::endl;
    std::cout << setBur << std::endl;
    Bureaucrat copiedBur = Bureaucrat(setBur);
    std::cout << "Debugging copiedBur(copied from setBur):" << std::endl;
    std::cout << copiedBur << std::endl;
    std::cout << "Assigning default bur to setbur and debugging it:" << std::endl;
    defaultBur = setBur;
    std::cout << defaultBur << std::endl;
    try 
    { 
        std::cout << "Instantiating bureaucrat with grade too high:" << std::endl;
        Bureaucrat tooHigh = Bureaucrat(0, "tooHigh");
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Caught GradeTooHighException as expected, Exception.what: " << e.what() << std::endl; 
    }
    try 
    {
        std::cout << "Instantiating bureaucrat with grade too low:" << std::endl;
        Bureaucrat tooLow = Bureaucrat(151, "tooHigh");
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Caught GradeTooLowException as expected, Exception.what: " << e.what()  << std::endl;
    }
}

void testIncrements()
{
    std::cout << "---------------testing increments---------------" << std::endl;
    try 
    {
        std::cout << "Instantiating bureaucrat with grade 1 and calling increment:" << std::endl;
        Bureaucrat maxGrade = Bureaucrat(1, "maxGrade");
        std::cout << maxGrade;
        maxGrade.incrementGrade();
    }
    catch (Bureaucrat::GradeTooHighException& e)
    {
        std::cout << "Caught GradeTooLowException as expected, Exception.what: " << e.what()  << std::endl;
    }
    try 
    {
        std::cout << "Instantiating bureaucrat with grade 105 and calling decrement:" << std::endl;
        Bureaucrat minGrade = Bureaucrat(150, "minGrade");
        std::cout << minGrade;
        minGrade.decrementGrade();
    }
    catch (Bureaucrat::GradeTooLowException& e)
    {
        std::cout << "Caught GradeTooLowException as expected, Exception.what: " << e.what() << std::endl;
    }
}

int main()
{
    testCannon();
    testIncrements();
}