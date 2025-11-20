#include "../include/Array.hpp"
#include <cassert>

int test(void)
{
    std::cout << "===== TEST 1: CONSTRUCTORS =====" << std::endl;
    {
        Array<int> empty;
        assert(empty.size() == 0);
        printArray(empty, "empty");

        Array<int> arr1(5);
        assert(arr1.size() == 5);
        for (unsigned int i = 0; i < arr1.size(); ++i)
            arr1[i] = i * 10;
        printArray(arr1, "arr1");

        Array<int> arr2(arr1);
        printArray(arr2, "arr2 (copy of arr1)");
        assert(arr2.size() == arr1.size());
        for (unsigned int i = 0; i < arr2.size(); ++i)
            assert(arr2[i] == arr1[i]);
        printArray(arr2, "arr2");
    }

    std::cout << "\n===== TEST 2: OPERATOR = =====" << std::endl;
    {
        Array<std::string> a(3);
        a[0] = "Ana";
        a[1] = "42";
        a[2] = "Malaga";

        Array<std::string> b;
        b = a; // operator=

        assert(a.size() == b.size());
        for (unsigned int i = 0; i < a.size(); ++i)
            assert(a[i] == b[i]);

        printArray(a, "a");
        printArray(b, "b (copied from a)");

        Array<std::string> c;
        c = b = a;
        printArray(c, "c (chained assignment from b = a)");
    }

    std::cout << "\n===== TEST 3: ACCESS WITH operator[] =====" << std::endl;
    {
        Array<double> nums(4);
        for (unsigned int i = 0; i < nums.size(); ++i)
            nums[i] = i + 0.5;

        printArray(nums, "nums");

        const Array<double> constNums(nums);
        assert(constNums[0] == 0.5);
        assert(constNums[3] == 3.5);

        try
        {
            std::cout << nums[10] << std::endl;
            assert(false);
        }
        catch (const std::out_of_range& e)
        {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "\n===== TEST 4: ITERATOR =====" << std::endl;
    {
        Array<int> arr(5);
        for (unsigned int i = 0; i < arr.size(); ++i)
            arr[i] = i + 1;

        std::cout << "With not const ";

        Array<int>::Iterator it = arr.begin();
        while (it != arr.end())
        {
            std::cout << *it << " ";
            it++;
        }
        std::cout << std::endl;

        std::cout << "Post and pre increment ";
        it = arr.begin();
        std::cout << *it++ << " "; // the value before
        std::cout << *it << " ";   // the following value
        
        ++it;
        std::cout << *it << " ";
        std::cout << std::endl;

        // Change with iterator
        Array<int>::Iterator it2 = arr.begin();
        while ( it2 != arr.end())
        {
            *it2 *= 2;
            ++it2;
        }
        printArray(arr, "arr modificado (cada valor * 2)");

        // Comparación ==
        Array<int>::Iterator itA = arr.begin();
        Array<int>::Iterator itB = arr.begin();
        assert(itA == itB);
        ++itB;
        assert(itA != itB);

        // Iterador const
        const Array<int> constArr(arr);
        std::cout << "With const: ";

        Array<int>::Iterator itC = constArr.begin();
        while( itC != constArr.end())
        {
            std::cout << *itC << " ";
            ++itC;
        }
        std::cout << std::endl;
    }

    std::cout << "\n===== TEST 5: COMPLEX TYPES =====" << std::endl;
    {
        Array<std::string> strs(3);
        strs[0] = "Hi";
        strs[1] = "from";
        strs[2] = "Array<T>";
        printArray(strs, "strs");

        Array<std::string> copyStrs(strs);
        printArray(copyStrs, "copyStrs");

        Array<std::string>::Iterator it = strs.begin();
        while (it != strs.end())
        {
            *it += "!";
            ++it;
        }
        printArray(strs, "strs change with iterator");
    }

    std::cout << "\n===== TEST 6: EMPTY ARRAYS =====" << std::endl;
    {
        Array<int> a;
        Array<int> b(a);
        Array<int> c;
        c = a;
        assert(a.size() == 0);
        assert(b.size() == 0);
        assert(c.size() == 0);
        printArray(a, "a empty");
        printArray(b, "b empty");
        printArray(c, "c empty");
    }

    std::cout << "\n✅ EVERYTHING IS OK ✅" << std::endl;
    return (0);
}
