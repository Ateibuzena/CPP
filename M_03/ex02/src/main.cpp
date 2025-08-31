#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    {
        std::cout << "\n---------------------GAME-------------------" << std::endl;

        const std::string a = "🐞";
        const std::string b = "🐛";

        FragTrap A(a);
        ScavTrap B(b);

        ft_print("", "ACTUAL STATE");
        A.printState(); /*not virtual method, here call frag method*/
        B.printState(); /*not virtual method, here call scav method*/

        int turn = 0; 
        while (A.getGame() && B.getGame())
        {
            ClapTrap* attacker;
            ClapTrap* target;

            if (!turn)
            {
                attacker = &B;
                target = &A;
            }
            else
            {
                attacker = &A;
                target = &B;
            }

            ft_print(attacker->getName(), " TURN");
            
            std::cout
                << "        Select a choice:\n"
                << "        1. ATTACK 💥\n"
                << "        2. REPAIR 🔧\n"
                << "        3. GATE KEEPER 🚪 (ScavTrap only)\n"
                << "        4. HIGH FIVE 🙌 (FragTrap only)\n"
                << "        5. EXIT\n"
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
                    attacker->beRepaired(target->getDamage());
                    break ;
                case 3:
                    {
                        ScavTrap* scav = dynamic_cast<ScavTrap*>(attacker);
                        if (scav)
                            scav->guardGate();
                        else
                            ft_print("", "Only ScavTrap can use Gate Keeper mode!");
                    }
                    break ;
                case 4:
                    {
                        FragTrap* frag = dynamic_cast<FragTrap*>(attacker);
                        if (frag)
                            frag->highFivesGuys();
                        else
                            ft_print("", "Only FragTrap can use High Five!");
                    }
                    break ;
                case 5:
                    ft_print("", "STOP GAME");
                    attacker->setGame(false);
                    target->setGame(false);
                    break ;
                default:
                    ft_print("", "INVALID OPTION");
                    continue ;
            }

            turn = !turn;
            
            if (A.getGame() && B.getGame())
            {
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
    }
    {   
        std::cout << "\n---------------------TEST-------------------" << std::endl;

        ScavTrap* scav_child = new ScavTrap("scav_child");
        ClapTrap* claptrap_child1 = scav_child; //pointer conversion, upcasting
        
        std::cout << "----------------------------------------" << std::endl;
        FragTrap* frag_child = new FragTrap("frag_child");
        ClapTrap* claptrap_child2 = frag_child; //pointer conversion, upcasting

        std::cout << "----------------------------------------" << std::endl;
        ClapTrap* father = new ClapTrap("father");

        
        std::cout << "\n-----------------------VIRTUAL ATTACK-----------------" << std::endl;
        /*virtual, call father method*/
        father->attack("🐛");          // ClapTrap::attack ✅ polymorphism 

        /*virtual, call scav_child method*/
        scav_child->attack("🐛");           // ScavTrap::attack ✅ polymorphism

        /*virtual, call frag_child method*/
        frag_child->attack("🐛");           // FragTrap::attack ✅ polymorphism

        /*virtual, call child method*/
        claptrap_child1->attack("🐛");  // ScavTrap::attack ✅ polymorphism

        /*virtual, call child method*/
        claptrap_child2->attack("🐛");  // ScavTrap::attack ✅ polymorphism

        std::cout << "\n-----------------------NOT VIRTUAL PRINTSTATE-----------------" << std::endl;
        /*not virtual, call father method*/
        father->printState();          // ClapTrap::printState ❌ not polymorphism

        /*not virtual, call father method*/
        scav_child->printState();           // ClapTrap::printState ❌ not polymorphism

        /*not virtual, call father method*/
        frag_child->printState();           // ClapTrap::printState ❌ not polymorphism

        /*not virtual, call father method*/
        claptrap_child1->printState();  // ClapTrap::printState ❌ not polymorphism

        /*not virtual, call father method*/
        claptrap_child2->printState();  // ClapTrap::printState ❌ not polymorphism

        std::cout << "\n-----------------------VIRTUAL DESTRUCTOR-----------------" << std::endl;
        /*virtual, call father method*/
        delete father;                 // ClapTrap::~ClapTrap ✅ polymorphism

        /*virtual, call child method*/
        delete claptrap_child2;         // FragTrap::~FragTrap ✅ polymorphism

        /*virtual, call child method*/
        delete claptrap_child1;         // ScavTrap::~ScavTrap ✅ polymorphism
    }
    return (0);
}