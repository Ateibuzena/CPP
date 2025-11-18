#include "Array.hpp"

/*---------------------------CONSTRUCTORS----------------------------*/

template <typename T>
Array<T>::Iterator::Iterator()
    :   _ptr(NULL)
{

}

template <typename T>
Array<T>::Iterator::Iterator(T* ptr)
    :   _ptr(ptr)
{

}

/*---------------------------METHODS----------------------------*/

template <typename T>
typename Array<T>::Iterator&   Array<T>::Iterator::operator=(const Iterator& object)
{
    if (this != &object)
        _ptr = object._ptr;

    return (*this);
}

template <typename T>
const T&    Array<T>::Iterator::operator*() const
{
    return (*_ptr);
}

template <typename T>
typename Array<T>::Iterator::reference  Array<T>::Iterator::operator*()
{
    return (*_ptr);
}

template <typename T>
const typename Array<T>::Iterator&   Array<T>::Iterator::operator++()
{
    _ptr = _ptr + 1;

    return (*this);
}

template <typename T>
typename Array<T>::Iterator   Array<T>::Iterator::operator++(int)
{
    Array<T>::Iterator  temp = *this;

    ++_ptr;

    return (temp);
}

template <typename T>
bool    Array<T>::Iterator::operator!=(const Iterator& object) const
{
    if (_ptr != object._ptr)
        return (true);
    return (false);
}

template <typename T>
bool    Array<T>::Iterator::operator==(const Iterator& object) const
{
    if (_ptr == object._ptr)
        return (true);
    return (false);
}

template <typename T>
typename Array<T>::Iterator::difference_type    Array<T>::Iterator::operator-(const Iterator& object) const
{
    return (_ptr - object._ptr);
}

template <typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator+(difference_type n) const
{
    return (Array<T>::Iterator(_ptr + n));
}

template <typename T>
typename Array<T>::Iterator Array<T>::Iterator::operator-(difference_type n) const
{
    return (Array<T>::Iterator(_ptr - n));
}

template <typename T>
const typename Array<T>::Iterator&  Array<T>::Iterator::operator+=(difference_type n)
{
    _ptr = _ptr + n;

    return (*this);
}

template <typename T>
const typename Array<T>::Iterator&  Array<T>::Iterator::operator-=(difference_type n)
{
    _ptr = _ptr - n;

    return (*this);
}

template <typename T>
bool    Array<T>::Iterator::operator<(const Iterator& object) const
{
    if (_ptr < object._ptr)
        return (true);
    return (false);
}

template <typename T>
bool    Array<T>::Iterator::operator<=(const Iterator& object) const
{
    if (_ptr <= object._ptr)
        return (true);
    return (false);
}

template <typename T>
bool    Array<T>::Iterator::operator>(const Iterator& object) const
{
    if (_ptr > object._ptr)
        return (true);
    return (false);
}

template <typename T>
bool    Array<T>::Iterator::operator>=(const Iterator& object) const
{
    if (_ptr >= object._ptr)
        return (true);
    return (false);
}
