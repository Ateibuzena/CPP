#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void)
{
    std::cout << "\n============ Creating base ClapTrap ============\n";
    ClapTrap clap("Clappy");
    std::cout << "\n----------------------------------------" << std::endl;

    clap.printState();
    std::cout << "\n----------------------------------------" << std::endl;

    clap.attack("target1");
    std::cout << "\n----------------------------------------" << std::endl;

    std::cout << "\n============ Creating ScavTrap ============\n";
    ScavTrap scav("Scavvy");
    std::cout << "\n----------------------------------------" << std::endl;

    scav.printState();
    std::cout << "\n----------------------------------------" << std::endl;

    scav.attack("target2");
    std::cout << "\n----------------------------------------" << std::endl;

    scav.guardGate();
    std::cout << "\n----------------------------------------" << std::endl;

    std::cout << "\n============ Creating FragTrap ============\n";
    FragTrap frag("Fraggy");
    std::cout << "\n----------------------------------------" << std::endl;

    frag.printState();
    std::cout << "\n----------------------------------------" << std::endl;

    frag.attack("target3");
    std::cout << "\n----------------------------------------" << std::endl;

    frag.highFivesGuys();
    std::cout << "\n----------------------------------------" << std::endl;

    std::cout << "\n============ Creating DiamondTrap ============\n";
    DiamondTrap diamond("Diama");
    std::cout << "\n----------------------------------------" << std::endl;

    diamond.printState();
    std::cout << "\n----------------------------------------" << std::endl;

    diamond.whoAmI();
    std::cout << "\n----------------------------------------" << std::endl;

    std::cout << "\n============ Testing DiamondTrap actions ============\n";
    diamond.attack("enemy");        // Should call ScavTrap::attack
    std::cout << "\n----------------------------------------" << std::endl;

    diamond.guardGate();            // From ScavTrap
    std::cout << "\n----------------------------------------" << std::endl;

    diamond.highFivesGuys();       // From FragTrap
    std::cout << "\n----------------------------------------" << std::endl;

    std::cout << "\n============ Copy DiamondTrap ============\n";
    DiamondTrap copyDiamond(diamond);
    std::cout << "\n----------------------------------------" << std::endl;

    copyDiamond.whoAmI();
    std::cout << "\n----------------------------------------" << std::endl;

    std::cout << "\n============ Assign DiamondTrap ============\n";
    DiamondTrap assignedDiamond;
    std::cout << "\n----------------------------------------" << std::endl;

    assignedDiamond = diamond;
    std::cout << "\n----------------------------------------" << std::endl;

    assignedDiamond.whoAmI();
    std::cout << "\n----------------------------------------" << std::endl;

    /*Destructors
    1. assignedDiamond
    2. copyDiamond
    3. diamond
    4. frag
    5. scav
    6. clap*/
    return (0);
}
