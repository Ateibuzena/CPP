#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include <iostream>
# include "WrongAnimal.hpp"

class   WrongCat: public WrongAnimal
{
    private:
    
    public:
                        WrongCat();
                        WrongCat(const std::string& typeValue);
                        WrongCat(const WrongCat& object);
        WrongCat&       operator=(const WrongCat& object);

                        ~WrongCat();
        
        void            makeSound(void) const;
};

#endif