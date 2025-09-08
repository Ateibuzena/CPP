#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class   Cat: public Animal
{
    private:
    
    public:
                Cat();
                Cat(const std::string& typeValue, const Brain& brainValue);
                Cat(const Cat& object);
        Cat&    operator=(const Cat& object);

                ~Cat();
        
        void    makeSound(void) const;
};

#endif