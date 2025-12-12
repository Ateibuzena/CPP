#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

/* ************************************************************************** */
/*                              TEMPLATE ITER                                 */
/* ************************************************************************** */
/*
 * iter: calls a function on each element of an array.
 * - array: pointer to the array of elements of type T
 * - length: number of elements
 * - func: function to apply to each element
 */

/* ------------------ non-const iter (elements may be modified) ------------------ */
/*template <typename T, typename F>
void iter(T* array, const size_t length, F func(T&))
{
    std::cout << "[ ";
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
    std::cout << "]" << std::endl;
}

template <typename T, typename F>
void iter(const T* array, const size_t length, F func(T&))
{
    std::cout << "[ ";
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
    std::cout << "]" << std::endl;
}*/

template <typename T, typename F>
void iter(T* array, const size_t length, F func)
{
    std::cout << "[ ";
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
    std::cout << "]" << std::endl;
}

/*
template <typename T, typename F>
void iter(const T* array, const size_t length, F func(T))
{
    std::cout << "[ ";
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
    std::cout << "]" << std::endl;
}

template <typename T, typename F>
void iter(T* array, const size_t length, F func(const T))
{
    std::cout << "[ ";
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
    std::cout << "]" << std::endl;
}*/

/* ------------------ const iter (read-only elements) ------------------ */
/*template <typename T, typename F>
void iter(const T* array, const size_t length, F func(const T))
{
    std::cout << "AAAAAAA" << std::endl;
    std::cout << "[ ";
    for (size_t i = 0; i < length; ++i)
        func(array[i]);   // func should be void func(const T&) or void func(T) that can accept const T
    std::cout << "]" << std::endl;
}*/

/* ************************************************************************** */
/*                           PRINT FUNCTIONS                                  */
/* ************************************************************************** */

/* Template function compatible with iterByValue */
template <typename T>
void ft_printCopy(T x)
{
    std::cout << x << " ";
}

//probar con un template que no recibe const &
/* Print for simple types (int, char, string, Vector, etc.) */
template <typename T>
void printTemplate(const T& c)
{
    std::cout << c << ", ";
}

/* Print for indexable elements like arrays or fixed-size C arrays */
template <typename T, size_t N>
void printArray(const T (&arr)[N])
{
    std::cout << "[ ";
    for (size_t i = 0; i < N; ++i)
    {
        std::cout << arr[i];
        if (i < N - 1)
            std::cout << ", ";
    }
    std::cout << "], ";
}

#endif
