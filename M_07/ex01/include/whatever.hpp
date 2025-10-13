#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

/* ************************************************************************** */
/*                          ITER TEMPLATE FUNCTIONS                            */
/* ************************************************************************** */

/* 
 * iter: basic version of an iterator function
 * - array: pointer to an array of elements of type T
 * - length: size of the array
 * - f: function to be called on each element
 * 
 * Expected function f: void func(T&) or void func(const T&)
 * Passes each element of the array to f according to its reference.
 */
template <typename T, typename F>
void iterExample(T *array, const size_t length, F f)
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

/* ************************************************************************** */
/*                        EXAMPLES OF FUNCTIONS FOR ITER                     */
/* ************************************************************************** */

/* Specific function for int */
/*void printInt(const int& x)
{
    std::cout << x << " ";
}*/

/* Specific function for arrayInt */
/*void printArrayInt(const int& x, const size_t length)
{
    int i = 0;

    while (i < length)
        std::cout << x << " ";
}*/

/* Specific function for char */
/*void printChar(char& c)
{
    std::cout << c << " ";
}*/

/* Template function that works for any type that has operator<< */
template <typename T>
void ft_print(T& c) 
{
    std::cout << c << " ";
}

/* Template function that works for any type that has operator<< */
/*template <typename T>
void ft_printArray(T& c, const size_t len_c) 
{
    for (size_t i = 0; i < len_c; i++)
        std::cout << c[i] << " ";
}*/

/* Template function that works for any type that has operator<< and ++preincrement. Change c*/
template <typename T>
void ft_printOneMore(T& c) 
{
    std::cout << ++c << " ";
}

/* ************************************************************************** */
/*                ITER THAT PASSES EACH ELEMENT BY VALUE                       */
/* ************************************************************************** */

/*
 * iterByValue: passes each element of the array by value to the function
 * This means the function cannot modify the original array.
 */
template <typename T, typename F>
void iterByValue(T *array, const size_t length, F func)
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);  // array[i] is copied
}

/* Template function compatible with iterByValue */
template <typename T>
void ft_printCopy(T x)
{
    std::cout << x << " ";
}

/* ************************************************************************** */
/*                  ITER THAT RETURNS THE RESULT OF THE FUNCTION               */
/* ************************************************************************** */

/*
 * iterReturn: calls a function that returns T and returns the last result
 * - useful for functions that transform elements and return the same type
 */
template <typename T, typename F>
T iterReturn(T *array, const size_t length, F func)
{
    T last = {0};
    for (size_t i = 0; i < length; ++i)
        last = func(array[i]);  // func must return T
    return (last);  // returns the last value
}

/* Example: double a value */
template <typename T>
T ft_double(T x)
{
    return (x * 2);
}

/* ************************************************************************** */
/*            ITER THAT RETURNS ANOTHER DATA TYPE (D)                         */
/* ************************************************************************** */

/*
 * iterReturnOther: calls a function that returns a type D different from T
 * - useful for transformations between different types
 */
template <typename T, typename F, typename D>
D iterReturnOther(T *array, const size_t length, F func)
{
    D last = {0};
    for (size_t i = 0; i < length; ++i)
        last = func(array[i]);  // func returns something convertible to D
    return last;
}

/* Example: get half of a value as double */
template <typename T, typename D>
D ft_mixDataExample(T x)
{
    return (x / 2.0);
}

/* ************************************************************************** */
/*             ITER THAT RETURNS SOMETHING EVEN IF FUNCTION RETURNS VOID       */
/* ************************************************************************** */

/*
 * iterVoidReturn: calls functions that return void
 * Returns an arbitrary value, for example, the size of the array
 */
template <typename T, typename F>
int iterVoidReturn(T *array, const size_t length, F func)
{
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
    return (length); // returns extra info
}

/* ************************************************************************** */
/*             ITER THAT PASSES EXTRA PARAMETERS TO THE FUNCTION              */
/* ************************************************************************** */

/*
 * iterExtra: passes each element and an extra parameter (length)
 * - useful if the function needs additional information
 */
template <typename T, typename F>
void iterExtra(T *array, const size_t length, F func)
{
    for (size_t i = 0; i < length; ++i)
        func(array[i], length);  // func must accept two parameters
}

/* Example: print with the array size */
template <typename T>
void ft_printAll(T x, size_t size)
{
    std::cout << "value: " << x << " size: " << size << " ";
}

#endif
