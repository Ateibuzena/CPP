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
        std::cout << j->getType() << " " << std::endl;
        j->makeSound();
        delete j;
        std::cout << "--------------------------------" << std::endl;
        
        const Animal* i = new Cat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        delete i;
        std::cout << "--------------------------------" << std::endl;
        
        const Animal* meta = new Animal();
        std::cout << meta->getType() << " " << std::endl;
        meta->makeSound();
        delete meta;
        std::cout << "--------------------------------" << std::endl;
    }

    return (0);
}