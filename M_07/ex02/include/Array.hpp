#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>

template <typename T>

class Array
{
    private:
        T*              _array;
        unsigned int    _size;
    
    public:
                        Array()
                            :   _array(NULL),
                                _size(0)
                        {
                            std::cout << "Empty array created" << std::endl;
                        };

                        Array(unsigned int sizeValue)
                            :   _array(new T[sizeValue]()), // Call constructor of T data
                                _size(sizeValue)
                        {

                        };

                        Array(const Array& object)
                            :   _array(new T[object._size]()),
                                _size(object._size)
                        {
                            for (unsigned int i = 0; i < _size; i++)
                                _array[i] = object._array[i];
                        }

                Array&  operator=(const Array& object)
                {
                    if (this != &object)
                    {
                        delete[] (_array);
                        _array = NULL;
                    }

                    _size = object._size;
                    _array = new T[object._size]();
                    for (unsigned int i = 0; i < _size; i++)
                        _array[i] = object._array[i];

                    return (*this);
                }

                        ~Array()
                        {
                            delete[] (_array);
                            _array = NULL;
                        };
}
