#include <iostream>
#include <string>
#include "whatever.hpp"
#include "iter.hpp"
#include "Vector.hpp"

static double   ft_halfInt(int x)
{
    return (x / 2.0);
};

int main(void)
{
    {
        std::cout << "=== LABORATORY: iter example templates with T = int and D = double ===\n\n";

        {
            int             intArray[] = {1, 2, 3, 4, 5};
            int             len = 5;

            // 1️⃣ Basic iter with T& (modification possible)
            std::cout << "1.a) Basic iter with references (T&): ";
            iterExample<int, void(*)(const int&)>(intArray, len, printInt);
            std::cout << std::endl;

            std::cout << "1.b) Basic iter with references (T&) and modification: ";
            iterExample(intArray, len, ft_printOneMore<int>);
            std::cout << std::endl;
        }

        {
            int             intArray[] = {1, 2, 3, 4, 5};
            int             len = 5;

            // 2️⃣ iterByValue (T passed by value)
            std::cout << "2) iterByValue with values (T passed by value): ";
            iterByValue(intArray, len, ft_printCopy<int>); // prints: 1 2 3 4 5
            std::cout << std::endl;
        }
        {
            int             intArray[] = {1, 2, 3, 4, 5};
            int             len = 5;
            
            // 3️⃣ iterReturn (function returns T, last value is returned)
            std::cout << "3) iterReturn (function returns T, last value): ";
            int lastValue = iterReturn(intArray, len, ft_double<int>); // last = 5*2 = 10
            std::cout << "lastValue * 2 = " << lastValue << std::endl;
        }
        {
            int             intArray[] = {1, 2, 3, 4, 5};
            int             len = 5;

            // 4️⃣ iterReturnOther (function returns D)
            std::cout << "4) iterReturnOther (function returns double from int) instanciate ft_half: ";
            double result = iterReturnOther<int, double(*)(int), double>(intArray, len, ft_halfInt);
            std::cout << "last value / 2.0 = " << result << std::endl;
        }
        {
            int             intArray[] = {1, 2, 3, 4, 5};
            int             len = 5; 

            // 5️⃣ iterVoidReturn (function returns void, iter returns info)
            std::cout << "5) iterVoidReturn (void function, iter returns length): ";
            int returnedLen = iterVoidReturn(intArray, len, ft_print<int>); // prints array
            std::cout << "| returnedLen = " << returnedLen << std::endl;
        }
        {
            int             intArray[] = {1, 2, 3, 4, 5};
            int             len = 5; 

            // 6️⃣ iterExtra (passing extra parameters)
            std::cout << "6) iterExtra (element + extra param): ";
            iterExtra(intArray, len, ft_printAll<int>); // prints: 1/5 2/5 3/5 4/5 5/5
            std::cout << std::endl;
        }

        std::cout << "\n=== END OF LAB ===\n" << std::endl;
    }
    
    {
        std::cout << "=== TESTING ITER FUNCTION ===\n\n";

        {
            // Test 1: integers
            int             arrInt[] = {1, 2, 3, 4, 5};
            const size_t    lenInt = 5;

            std::cout << "Integers (template print): ";
            iter(arrInt, lenInt, printTemplate<int>);  // using template
            std::cout << std::endl;
        }
        {
            // Test 2: characters
            char            arrChar[] = {'a', 'b', 'c', 'd'};
            const size_t    lenChar = 4;

            std::cout << "Characters (template print): ";
            iter(arrChar, lenChar, printTemplate<char>); // template function
            std::cout << std::endl;
        }
        {
            // Test 3: strings
            std::string     arrStr[] = {"Hello", "World", "42"};
            const size_t    lenStr = 3;

            std::cout << "Strings (template print): ";
            iter(arrStr, lenStr, printTemplate<std::string>); // template function
            std::cout << std::endl;
        }
    }

    {
        {
            // Test 1: integers
            const int       arrInt[] = {1, 2, 3, 4, 5};
            const size_t    lenInt = 5;

            std::cout << "Const Integers (template print): ";
            iter(arrInt, lenInt, printTemplate<int>);  // using template
            std::cout << std::endl;
        }
        {
            // Test 2: characters
            const char      arrChar[] = {'a', 'b', 'c', 'd'};
            const size_t    lenChar = 4;

            std::cout << "Const Characters (template print): ";
            iter(arrChar, lenChar, printTemplate<char>); // template function
            std::cout << std::endl;
        }
        {
            // Test 3: strings
            const std::string   arrStr[] = {"Hello", "World", "42"};
            const size_t        lenStr = 3;

            std::cout << "Const Strings (template print): ";
            iter(arrStr, lenStr, printTemplate<std::string>); // template function
            std::cout << std::endl;
        }
    }
        std::cout << "\n=== END OF TESTING ITER ===\n" << std::endl;
    {
        {
            std::cout << "=== MY TESTING TEMPLATE FOR ARRAYS ===\n\n";

            {
                // ---------------- Simple int array ----------------
                int         arrInt[] = {1,2,3,4,5};
                size_t      lenInt = 5;

                std::cout << "Simple int array: ";
                iter(arrInt, lenInt, printTemplate<int>);
                std::cout << std::endl;
            }
            {
                // ---------------- Array of arrays ----------------
                int         arr2D[2][3] = { {1,2,3}, {4,5,6} };
                size_t      len2D = 2;

                std::cout << "Array of arrays: ";
                iter(arr2D, len2D, printArray<int,3>);
                std::cout << std::endl;
            }
            {
                // ---------------- Char array ----------------
                char        arrChar[] = {'a','b','c'};
                size_t      lenChar = 3;

                std::cout << "Char array: ";
                iter(arrChar, lenChar, printTemplate<char>);
                std::cout << std::endl;
            }
            {
                // ---------------- Array of char arrays ----------------
                char    arrChar2D[2][5] = { "abcd", "wxyz" };
                size_t  lenChar2D = 2;

                std::cout << "Array of char arrays: ";
                iter(arrChar2D, lenChar2D, printArray<char,5>);
                std::cout << std::endl;
            }
            {
                // ---------------- Array of strings ----------------
                std::string     arrStr[] = {"Hello","World","42"};
                size_t          lenStr = 3;

                std::cout << "Array of strings: ";
                iter(arrStr, lenStr, printTemplate<std::string>);
                std::cout << std::endl;
            }

            std::cout << "\n=== END OF TESTING MY TEMPLATE FOR ARRAYS ===\n" << std::endl;
        }

        {
            std::cout << "=== MY VECTOR CLASS ===\n\n";

            Vector a(1,2,3);
            Vector b(4,5,6);

            Vector c = a + b;   // suma
            Vector d = a * 2;   // escalar
            double dotProd = a.dot(b);

            std::cout << "a = " << a << "\n";
            std::cout << "b = " << b << "\n";
            std::cout << "c = " << c << "\n";
            std::cout << "d = " << d << "\n";
            std::cout << "dot(a,b) = " << dotProd << "\n";

            std::cout << "a == b → " << (a == b) << std::endl;
            std::cout << "a == c → " << (a == c) << std::endl;
            std::cout << "a < b → "  << (a < b) << std::endl;

            Vector vmin = std::min(a, b);
            Vector vmax = std::max(a, b);

            std::cout << "min(a, b) = " << vmin << "\n";
            std::cout << "max(a, b) = " << vmax << "\n";

            Vector arr[4] = { a, b, c, d };
            size_t len = 4;

            std::cout << "Array of Vectors: ";
            iter(arr, len, printTemplate<Vector>);
            std::cout << std::endl;

            std::cout << "\n=== END OF TESTING VECTOR CLASS AND ITER ===\n" << std::endl;
        }
    }
    return (0);
}