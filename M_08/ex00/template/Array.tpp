#include "Array.hpp"

/*---------------------------CONSTRUCTORS----------------------------*/

template <typename T>
Array<T>::Array()
    :   _size(0),
        _data(NULL)
        
{
    //std::cout << "My Array class" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n)
    :   _size(n),
        _data(new T[n]())
        
{
    //std::cout << "My Array class" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& object)
    :   _size(object._size),
        _data(new T[object._size]())
        
{
    unsigned int i = 0;
    while (i < _size)
    {
        _data[i] = object._data[i]; //método getElement = [i]
        i++;
    }
}

template <typename T> //(placement new)
Array<T>&   Array<T>::operator=(const Array<T>& object)
{
    if (this != &object)
    {
        this->~Array();
        new (this) Array(object);
    }
    
    return (*this);
}

/*---------------------------DESTRUCTORS----------------------------*/

template <typename T>
Array<T>::~Array()
{
    delete[] (_data);
    _data = NULL;
}

/*---------------------------GETTERS----------------------------*/

template <typename T>
unsigned int  Array<T>::size(void) const
{
    return (_size);
}

template <typename T>
const T&  Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw (std::out_of_range("Index out of range"));
    
    return (_data[i]);
}

template <typename T>
T&    Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw (std::out_of_range("Index out of range"));
    
    return (_data[i]);
}

/*---------------------------METHODS----------------------------*/

template <typename T>
bool    Array<T>::operator==(const Array& object) const
{
    if (_size != object._size)
        return (false);

    for (unsigned int i = 0; i < _size; i++)
    {
        if (_data[i] != object._data[i])
            return (false);
    }
    
    return (true);
}

template <typename T>
typename Array<T>::Iterator    Array<T>::begin()
{
    return (Iterator(_data));
}

template <typename T>
typename Array<T>::Iterator    Array<T>::end()
{
    return (Iterator(_data + _size));
}

template <typename T>
const typename Array<T>::Iterator  Array<T>::begin() const
{
    return (Iterator(_data));
}

template <typename T>
const typename Array<T>::Iterator  Array<T>::end() const
{
    return (Iterator(_data + _size));
}
