#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class   Animal
{
    private:
        std::string _type;
    
    public:
                            Animal();
                            Animal(const std::string& typeValue);
                            Animal(const Animal& object);
        Animal&             operator=(const Animal& object);

        virtual             ~Animal();

        const std::string&  getType(void) const;

        void                setType(const std::string& nameValue);

        virtual void        makeSound(void) const;
};

#endif