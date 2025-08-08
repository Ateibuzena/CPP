#include "Harl.hpp"

int main(void)
{
    {
        Harl    harl;
        std::cout << "---------------------------------------" << std::endl;

        std::string input;

        std::cout
            << "Enter a level (DEBUG, INFO, WARNING, ERROR): "
            << std::endl;

        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout
                << "\nEOF detected. Exiting."
                << std::endl;
            return (1);
        }
        std::cout << "---------------------------------------" << std::endl;
        harl.complain(input);
        std::cout << "---------------------------------------" << std::endl;
    }
}