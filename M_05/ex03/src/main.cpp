#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

    // ---------------- INTERN ----------------
    std::cout << "\n--- Intern creates forms ---\n";

    Intern intern;

    AForm* malagaTrees = intern.makeForm("shrubbery creation", "Campus42Malaga");
    AForm* intraUpdate = intern.makeForm("robotomy request", "Intra42Malaga");
    AForm* alvaroPardon = intern.makeForm("presidential pardon", "Álvaro Valiente");
    AForm* unknownForm = intern.makeForm("unknown form", "Nobody"); // Prueba error

    // ---------------- PRINT FORMS ----------------
    std::cout << "\n--- Forms created ---\n";
    if (malagaTrees)
        std::cout
                << *malagaTrees
                << "\n\n";
    if (intraUpdate)
        std::cout
                << *intraUpdate
                << "\n\n";
    if (alvaroPardon)
        std::cout
                << *alvaroPardon
                << "\n\n";
    if (unknownForm)
        std::cout
                << *unknownForm
                << "\n\n";

    // ---------------- SIGNING ----------------
    std::cout << "\n--- Signing attempts ---\n";
    
    Bureaucrat bureaucrats[] = {zaphod, ford, arthur};
    AForm* forms[] = {malagaTrees, intraUpdate, alvaroPardon, unknownForm};

    int i = 0;
    while (i < 3)
    {
        Bureaucrat &b = bureaucrats[i];

        std::cout
                << "\nSigning forms with "
                << b.getName()
                << "\n";

        int j = 0;
        while (j < 4)
        {
            if (forms[j]) 
            {
                std::cout
                        << "\nForm: "
                        << forms[j]->getName()
                        << "\n";
                b.signForm(*forms[j]);
            }
            j++;
        }
        i++;
    }

    // ---------------- EXECUTIONS ----------------
    std::cout << "\n--- Executions ---\n";
    for (int i = 0; i < 3; ++i)
    {
        Bureaucrat &b = bureaucrats[i];

        std::cout
                << "\nExecuting forms with "
                << b.getName()
                << "\n";

        for (int j = 0; j < 3; ++j)
        {
            if (forms[j])
            {
                try
                {
                    forms[j]->execute(b);
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << std::endl;
                }
            }
        }
    }

    // ---------------- CLEANUP ----------------
    delete malagaTrees;
    delete intraUpdate;
    delete alvaroPardon;
    delete unknownForm;

    std::cout << "\n--- SIMULATION END ---\n";
    return 0;
}
