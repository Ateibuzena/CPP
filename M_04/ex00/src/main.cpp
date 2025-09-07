#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
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
    
    const WrongAnimal* animal = new WrongAnimal();
    std::cout << animal->getType() << " " << std::endl;
    animal->makeSound();
    delete animal;
    std::cout << "--------------------------------" << std::endl;
    
    const WrongAnimal* cat = new WrongCat();
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound();
    delete cat;
    std::cout << "--------------------------------" << std::endl;

    return (0);
}