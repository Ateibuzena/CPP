#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class   Dog: public Animal
{
    private:
    
    public:
                Dog();
                Dog(const std::string& typeValue, const Brain& brainValue);
                Dog(const Dog& object);
        Dog&    operator=(const Dog& object);

                ~Dog();

        void    makeSound(void) const;
};

#endif