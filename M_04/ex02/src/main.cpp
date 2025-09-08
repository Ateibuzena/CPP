#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
    {
        Animal* animals[10];

        int i = 0;
        while (i < 5)
        {
            animals[i] = new Dog();
            std::cout << "--------------------------------" << std::endl;
            animals[i + 5] = new Cat();
            std::cout << "--------------------------------" << std::endl;
            i++;
        }
        i = 0;
        while (i < 10)
        {
            delete animals[i];
            std::cout << "--------------------------------" << std::endl;
            i++;
        }
    }
    {
        const Animal* j = new Dog();
        std::cout << "--------------------------------" << std::endl;
        std::cout
            << "Type: "
            << j->getType()
            << std::endl;
        std::cout << "--------------------------------" << std::endl;
        j->makeSound();
        std::cout << "--------------------------------" << std::endl;
        delete j;
        std::cout << "--------------------------------" << std::endl;
        
        const Animal* i = new Cat();
        std::cout << "--------------------------------" << std::endl;
        std::cout
            << "Type: "
            << i->getType()
            << std::endl;
        std::cout << "--------------------------------" << std::endl;
        i->makeSound();
        std::cout << "--------------------------------" << std::endl;
        delete i;
        std::cout << "--------------------------------" << std::endl;
        
        /*const Animal* meta = new Animal();
        std::cout << "--------------------------------" << std::endl;
        std::cout
            << "Type: "
            << meta->getType()
            << std::endl;
        std::cout << "--------------------------------" << std::endl;
        meta->makeSound();
        std::cout << "--------------------------------" << std::endl;
        delete meta;
        std::cout << "--------------------------------" << std::endl;*/
    }

    return (0);
}