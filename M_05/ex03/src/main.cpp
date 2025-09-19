#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    // ---------------- BUREAUCRATS ----------------
    std::cout << "\n--- Bureaucrats ---\n";
    Bureaucrat zaphod("Zaphod Beeblebrox", 1);  // High authority
    Bureaucrat ford("Ford Perfect", 50);         // Mid-level authority
    Bureaucrat arthur("Arthur Dent", 150);       // Low-level authority

    std::cout
            << zaphod
            << "\n\n"
            << ford
            << "\n\n"
            << arthur
            << "\n\n";

    // ---------------- FORMS ----------------
    std::cout << "\n--- Forms creations ---\n";
    ShrubberyCreationForm malagaTrees("Campus42Malaga");
    RobotomyRequestForm intraUpdate("Intra42Malaga");
    PresidentialPardonForm alvaroPardon("Álvaro Valiente");

    std::cout
            << malagaTrees
            << "\n\n"
            << intraUpdate
            << "\n\n"
            << alvaroPardon
            << "\n\n";

    // ---------------- SIGNING ----------------
    std::cout << "\n--- Signing attempts ---\n";
    
    ford.signForm(malagaTrees);
    ford.signForm(intraUpdate);
    ford.signForm(alvaroPardon);

    std::cout
            << malagaTrees
            << "\n\n"
            << intraUpdate
            << "\n\n"
            << alvaroPardon
            << "\n\n";

    arthur.signForm(malagaTrees);
    arthur.signForm(intraUpdate);
    arthur.signForm(alvaroPardon);

    std::cout
            << malagaTrees
            << "\n\n"
            << intraUpdate
            << "\n\n"
            << alvaroPardon
            << "\n\n";

    zaphod.signForm(malagaTrees);
    zaphod.signForm(intraUpdate);
    zaphod.signForm(alvaroPardon);

    std::cout
            << malagaTrees
            << "\n\n"
            << intraUpdate
            << "\n\n"
            << alvaroPardon
            << "\n\n";

    // ---------------- EXECUTIONS ----------------
    std::cout << "\n--- Executions ---\n";

    Bureaucrat bureaucrats[] = {zaphod, ford, arthur};
    AForm* forms[] = {&malagaTrees, &intraUpdate, &alvaroPardon};

    for (int i = 0; i < 3; ++i)
    {
        Bureaucrat &b = bureaucrats[i];
        std::cout << "\nExecuting forms with " << b.getName() << ":\n";

        for (int j = 0; j < 3; ++j)
        {
            AForm *f = forms[j];
            try
            {
                f->execute(b);
            }
            catch (const std::exception &e)
            {
                std::cerr << e.what() << std::endl;
            }
        }
    }

    std::cout << "\n--- SIMULATION END ---\n";

    return (0);
}
