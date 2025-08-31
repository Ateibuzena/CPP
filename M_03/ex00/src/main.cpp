#include "ClapTrap.hpp"

static void    ft_print(const std::string& c, const std::string& sms)
{
    std::cout << "\n        " << c << sms << "\n" << std::endl;
}

static int clearInputBuffer()
{
    int count = 0;

    while (std::cin.peek() != '\n'
            && std::cin.peek() != std::char_traits<char>::eof())
    {
        std::cin.get();
        ++count;
    }
    if (std::cin.peek() == '\n')
        std::cin.get();
    return (count);
}

int main(void)
{
    const std::string   a = "🐞";
    const std::string   b = "🐛";

    ClapTrap A(a);
    ClapTrap B(b);

    ft_print("", "ACTUAL STATE");
    A.printState();
    B.printState();

    int turn = 0; 
    while (A.getGame() && B.getGame())
    {
        ClapTrap *attacker;
        ClapTrap *target;
        if (!turn)
        {
            attacker = &A;
            target = &B;
        }
        else
        {
            attacker = &B;
            target = &A;
        }

        ft_print(attacker->getName(), " TURN");
        
        std::cout
                << "        Select a choice:\n"
                << "        1. ATTACK 💥\n"
                << "        2. REPAIR 🔧\n"
                << "        3. EXIT\n"
                << "        Choice: ";

        int choice;

        if (std::cin.eof())
        {
            std::cout << "\nEOF detected. Exiting." << std::endl;
            break ;
        }

        if (!(std::cin >> choice))
        {
            std::cin.clear();
            clearInputBuffer();
            ft_print("", "INVALID OPTION");
            continue ;
        }

        switch (choice)
        {
            case 1:
                attacker->attack(target->getName());
                target->takeDamage(attacker->getDamage());
                break ;
            case 2:
                attacker->beRepaired(attacker->getDamage());
                break ;
            case 3:
                ft_print("", "STOP GAME");
                attacker->setGame(false);
                target->setGame(false);
                break ;
            default:
                ft_print("", "INVALID OPTION");
                continue ;
        }
        
        if (!turn)
            turn = 1;
        else
            turn = 0;
        if (A.getGame() && B.getGame())
        {
            ft_print("", "ACTUAL STATE");
            A.printState();
            B.printState();
        }
    }

    if (!A.getHit() || !B.getHit())
    {
        if (A.getHit() == B.getHit() && A.getHit() == 0)
            ft_print("", "DRAW");
        else if (A.getHit() == 0)
            ft_print(b, " WIN");
        else
            ft_print(a, " WIN");
    }
    
    return (0);
}