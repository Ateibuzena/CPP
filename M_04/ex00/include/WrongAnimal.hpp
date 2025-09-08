#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class   WrongAnimal
{
    private:
        std::string         _type;
    
    public:
                            WrongAnimal();
                            WrongAnimal(const std::string& typeValue);
                            WrongAnimal(const WrongAnimal& object);
        WrongAnimal&        operator=(const WrongAnimal& object);

                            ~WrongAnimal();

        const std::string&  getType(void) const;

        void                setType(const std::string& nameValue);

        void                makeSound(void) const;
};

#endif