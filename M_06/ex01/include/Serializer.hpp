#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <string>

typedef unsigned long int uintptr_t;

typedef struct Data_s
{
    int         key;
    std::string value;
}   Data;


class   Serializer
{
    private:
                            Serializer();
                            Serializer(const std::string& nameValue, int gradeValue);
                            Serializer(const Serializer& object);
        Serializer&         operator=(const Serializer& object);

                            ~Serializer();
    
    public:

        static uintptr_t           serialize(Data* ptr);
        static Data*               deserialize(uintptr_t raw);
};

# endif
