#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat  alice("Alice", 1);
    Bureaucrat  bob("Bob", 150);
    Bureaucrat  bureaucratUseless("Default Bureaucrat", 150);
    std::cerr << "--------------------------------" << std::endl;

    try
    {
        Bureaucrat temp("Bureaucrat Useless", 0);
        bureaucratUseless = temp; //can't execute it
    }
    catch (const std::exception& bureaucratError)
    {
        std::cerr << "Error:\n" << bureaucratError.what() << std::endl;
        std::cerr << "--------------------------------" << std::endl;
    }

    Form    formUseless("Default Form", 150, 150);
    Form    registration("Registration Form", 150, 150);
    Form    resignation("Resignation Form", 150, 1);
    Form    dismissal("Dismissal Form", 1, 1);

    try
    {
        Form tmp("Form Useless", 200, 0);
        formUseless = tmp; //can't execute it
    }
    catch (const std::exception& formError)
    {
        std::cerr << "Error:\n" << formError.what() << std::endl;
        std::cerr << "--------------------------------" << std::endl;
    }

    std::cout << alice << std::endl;
    alice.signForm(formUseless);
    alice.signForm(registration);
    alice.signForm(resignation);
    alice.signForm(dismissal);
    std::cout << "--------------------------------" << std::endl;

    std::cout << bob << std::endl;
    bob.signForm(formUseless);
    bob.signForm(registration);
    bob.signForm(resignation);
    bob.signForm(dismissal);
    std::cout << "--------------------------------" << std::endl;

    std::cout << bureaucratUseless << std::endl;
    bureaucratUseless.signForm(formUseless);
    bureaucratUseless.signForm(registration);
    bureaucratUseless.signForm(resignation);
    bureaucratUseless.signForm(dismissal);
    std::cout << "--------------------------------" << std::endl;

    return (0);
}
