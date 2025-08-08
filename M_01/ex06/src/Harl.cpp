#include "Harl.hpp"

void    (Harl::*Harl::_ft[4])(void) =
{
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};

std::string Harl::_levels[4] =
{
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR"
};

Harl::Harl()
    :   _className("Harl")
{
    std::cout
        << _className
        << ": Default constructor"
        << std::endl;
}

Harl::~Harl()
{
    std::cout
        << _className
        << ": Destructor"
        << std::endl;
}

void    Harl::complain(const std::string level)
{
    int i = 0;

    while (i < 4 && level != _levels[i])
        i++;

    switch(i)
    {
        case 0:
        case 1:
        case 2:
        case 3:
        {
            while (i < 4)
            {
                (this->*_ft[i])();
                std::cout << "---------------------------------------" << std::endl;
                std::cout
                    << _className
                    << ": Can complain"
                    << std::endl;
                i++;
            }
            break ;
        }
        default:
        {
            std::cout
                << _className
                << ": Can not complain"
                << std::endl;
        }
    }
}

void    Harl::debug(void)
{
    std::cout
        << "[DEBUG] "
        << "I'm here. 🐞"
        << std::endl;
}

void    Harl::info(void)
{
    std::cout
        << "[INFO] "
        << "We continue. ℹ️"
        << std::endl;
}

void    Harl::warning(void)
{
    std::cout
        << "[WARNING] "
        << "Something is weird. ⚠️"
        << std::endl;
}

void    Harl::error(void)
{
    std::cout
        << "[ERROR] "
        << "Error. ❌"
        << std::endl;
}
