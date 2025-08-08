#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout
            << "❌ Error: "
            << argv[0]
            << " <target>"
            << std::endl;
        return (1);
    }
    {
        Harl    harl;
        std::cout << "---------------------------------------" << std::endl;

        harl.complain(argv[1]);
        std::cout << "---------------------------------------" << std::endl;
    }
}