#include "Zombie.hpp"

static std::string  to_string(const int n)
{
    std::stringstream str;
    str << n;
    return (str.str());
}

Zombie* zombieHorde(const int N, const std::string nameValue)
{
    if (N <= 0)
        return (NULL);

    Zombie*  zombieHorde = new Zombie[N];

    int i = 0;
    while (i < N)
    {
        zombieHorde[i].setName(nameValue + to_string(0) + to_string(i));
        i++;
    }
    return (zombieHorde);
}

void    deleteHorde(const int N, Zombie* zombieHorde)
{
    int i = 0;
    while (i < N)
    {
        zombieHorde[i].getName();
        i++;
    }
    delete[] zombieHorde;
}