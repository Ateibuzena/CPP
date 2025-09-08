#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class   Animal
{
    private:
        std::string         _type;
        Brain               *_brain;
    
    public:
                            Animal();
                            Animal(const std::string& typeValue, const Brain& brainValue);
                            Animal(const Animal& object);
        Animal&             operator=(const Animal& object);

        virtual             ~Animal();

        const std::string&  getType(void) const;
        const Brain&        getBrain(void) const;

        void                setType(const std::string& nameValue);
        void                setBrain(const Brain& brainValue);

        virtual void        makeSound(void) const;
};

#endif