#include "MutantStack.hpp"
#include <list>

int main()
{
    std::list<int> mstack;

    mstack.push_back(5);
    mstack.push_back(17);

    std::cout << mstack.back() << std::endl;

    mstack.pop_front();

    std::cout << mstack.size() << std::endl;

    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    mstack.push_back(0);

    std::cout << mstack.front() << std::endl;
    std::cout << mstack.size() << std::endl;

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::list<int> s(mstack);

    return (0);
}