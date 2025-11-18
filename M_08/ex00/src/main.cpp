#include "easyfind.hpp"
#include "Print.hpp"
#include "Array.hpp"
#include <vector>
#include <map>
#include <string>
#include <set>

static void    testMyArrayOfIntegers(void)
{
    std::cout << "\n----- Testing easyfind with My Array of Integers -----\n" << std::endl;
    
    unsigned int i = 0;

    std::cout << "Creating Array of Integers with 5 elements" << std::endl;
    Array< int > arrayOfIntegers(5);

    std::cout << "Filling Array of Integers with values from 1 to 5" << std::endl;
    while (i < arrayOfIntegers.size())
    {
        arrayOfIntegers[i] = i + 1;
        i++;
    }
    printArray(arrayOfIntegers, "arrayOfIntegers ");

    Array< int >::Iterator it = arrayOfIntegers.begin();
    Array< int >::Iterator ite = arrayOfIntegers.end();

    std::cout << "Creating Integer to search for:" << std::endl;
    int set = 0;

    std::cout << "\nSearching for value " << set << " in the Array of Integers" << std::endl;
    Array< int >::iterator result;    
    try
    {
        result = easyfind(arrayOfIntegers, set);
        std::cout << "Value found: " << *result << std::endl;
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    result = std::find(it, ite, set);
    if (result != ite)
        std::cout << "Value found using std::find: " << *result << std::endl;
    else
        std::cout << "Value not found using std::find" << std::endl;

    std::cout << "\nSearching for value 3 in the Array of Integers again" << std::endl;
    set = 3;

    std::cout << "\nSearching for value " << set << " in the Array of Integers" << std::endl;
    try
    {
        result = easyfind(arrayOfIntegers, set);
        std::cout << "Value found: " << *result << std::endl;
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    result = std::find(it, ite, set);
    if (result != ite)
        std::cout << "Value found using std::find: " << *result << std::endl;
    else
        std::cout << "Value not found using std::find" << std::endl;

    std::cout << "Finished testing easyfind with My Array of Integers" << std::endl;
}

static void    testMyArrayOfArrays(void)
{
    std::cout << "\n----- Testing easyfind with My Array of Arrays -----\n" << std::endl;
    
    unsigned int i = 0;

    std::cout << "Creating Array of Arrays with 5 elements" << std::endl;
    Array< Array< int > > arrayOfArrays(5);

    std::cout << "Filling Array of Arrays with inner Arrays of 3 elements " << std::endl;
    while (i < arrayOfArrays.size())
    {
        std::cout << "Filling inner Array with values " << i + 1 << ", " << (i + 1) * 10 << ", " << (i + 1) * 100 << std::endl;
        Array< int > innerArray(3);
        innerArray[0] = i + 1;
        innerArray[1] = (i + 1) * 10;
        innerArray[2] = (i + 1) * 100;
        arrayOfArrays[i] = innerArray;
        i++;
    }
    printArray(arrayOfArrays, "arrayOfArrays ");

    Array< Array< int > >::Iterator it = arrayOfArrays.begin();
    Array< Array< int > >::Iterator ite = arrayOfArrays.end();

    std::cout << "Creating Array of Integers with 3 elements to search for" << std::endl;
    Array< int > set(3);
    set[0] = 4;
    set[1] = 40;
    set[2] = 400;
    printArray(set, "set ");

    std::cout << "\nSearching for Array in the Array of Arrays" << std::endl;
    Array< Array< int > >::Iterator result;
    try
    {
        result = easyfind(arrayOfArrays, set);
        std::cout << "Value found: ";
        printArray(*result, "result ");
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    result = std::find(it, ite, set);
    if (result != ite)
    {
        std::cout << "Value found using std::find: ";
        printArray(*result, "result ");
    }
    else
        std::cout << "Value not found using std::find" << std::endl;

    std::cout << "Finished testing easyfind with My Array of Arrays" << std::endl;
}

static void    testMyArrayOfVectors(void)
{
    std::cout << "\n----- Testing easyfind with My Array of Vectors -----\n" << std::endl;
    
    unsigned int i = 0;
    
    std::cout << "Creating Array of Vectors with 5 elements:" << std::endl;
    Array< std::vector< int > > arrayOfVectors(5);
    
    std::cout << "Filling Array of Vectors with inner Vectors of 3 elements: " << std::endl;
    while (i < arrayOfVectors.size())
    {
        std::cout << "Filling inner Vector with values: " << i + 1 << ", " << (i + 1) * 10 << ", " << (i + 1) * 100 << std::endl;
        std::vector< int > innerVector;
        innerVector.push_back(i + 1);
        innerVector.push_back((i + 1) * 10);
        innerVector.push_back((i + 1) * 100);
        arrayOfVectors[i] = innerVector;
        i++;
    }
    i = 0;
    while (i < arrayOfVectors.size())
    {
        printVector(arrayOfVectors[i], "arrayOfVectors[" + to_string_c98(i) + "] ");
        i++;
    }

    Array< std::vector< int > >::Iterator it = arrayOfVectors.begin();
    Array< std::vector< int > >::Iterator ite = arrayOfVectors.end();

    std::cout << "Creating Vector of Integers with 3 elements to search for:" << std::endl;
    std::vector< int > set;
    set.push_back(4);
    set.push_back(40);
    set.push_back(400);
    printVector(set, "set ");

    std::cout << "\nSearching for Vector in the Array of Vectors:" << std::endl;
    Array< std::vector< int > >::Iterator result;
    try
    {
        result = easyfind(arrayOfVectors, set);

        std::cout << "Value found: ";
        printVector(*result, "result ");
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    result = std::find(it, ite, set);
    if (result != ite)
    {
        std::cout << "Value found using std::find: ";
        printVector(*result, "result ");
    }
    else
        std::cout << "Value not found using std::find" << std::endl;
}

static void    testMyArrayOfMaps(void)
{
    std::cout << "\n----- Testing easyfind with My Array of Maps -----\n" << std::endl;

    unsigned int i = 0;

    std::cout << "Creating Array of Maps with 5 elements:" << std::endl;
    Array< std::map< int, std::string > > arrayOfMaps(5);

    std::cout << "Filling Array of Maps with inner Maps of 3 elements: " << std::endl;
    while (i < arrayOfMaps.size())
    {
        std::cout << "Filling inner Map with values: {" << i + 1 << ": \"Value" << i + 1 << "\", " << (i + 1) * 10 << ": \"Value" << (i + 1) * 10 << "\", " << (i + 1) * 100 << ": \"Value" << (i + 1) * 100 << "\"}" << std::endl;
        std::map< int, std::string > innerMap;
        innerMap[i + 1] = "Value" + to_string_c98(i + 1);
        innerMap[(i + 1) * 10] = "Value" + to_string_c98((i + 1) * 10);
        innerMap[(i + 1) * 100] = "Value" + to_string_c98((i + 1) * 100);
        arrayOfMaps[i] = innerMap;
        i++;
    }
    i = 0;
    while (i < arrayOfMaps.size())
    {
        printMap(arrayOfMaps[i], "arrayOfMaps[" + to_string_c98(i) + "] ");
        i++;
    }

    Array< std::map< int, std::string > >::Iterator it = arrayOfMaps.begin();
    Array< std::map< int, std::string > >::Iterator ite = arrayOfMaps.end();

    std::cout << "Creating Map of Integers to Strings with 3 elements to search for:" << std::endl;
    std::map< int, std::string > set;
    set[4] = "Value4";
    set[40] = "Value40";
    set[400] = "Value400";
    
    printMap(set, "set ");

    std::cout << "\nSearching for map in the Array of Maps:" << std::endl;
    Array< std::map< int, std::string > >::Iterator result;
    try
    {
        result = easyfind(arrayOfMaps, set);
        std::cout << "Value found: ";
        printMap(*result, "result ");
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    result = std::find(it, ite, set);
    if (result != ite)
    {
        std::cout << "Value found using std::find: ";
        printMap(*result, "result ");
    }
    else
        std::cout << "Value not found using std::find" << std::endl;
}

static void    testMyArrayOfStrings(void)
{
    std::cout << "\n----- Testing easyfind with My Array of Strings -----\n" << std::endl;

    unsigned int i = 0;

    std::cout << "Creating Array of Strings with 5 elements:" << std::endl;
    Array< std::string > arrayOfStrings(5); 

    std::cout << "Filling Array of Strings with values: " << std::endl;
    while (i < arrayOfStrings.size())
    {
        arrayOfStrings[i] = "String" + to_string_c98(i + 1);
        i++;
    }
    printArray(arrayOfStrings, "arrayOfStrings ");

    Array< std::string >::Iterator it = arrayOfStrings.begin();
    Array< std::string >::Iterator ite = arrayOfStrings.end();

    std::cout << "Creating String to search for:" << std::endl;
    std::string set = "String3";

    std::cout << "\nSearching for value \"" << set << "\" in the Array of Strings:" << std::endl;
    Array< std::string >::Iterator result;    
    try
    {
        result = easyfind(arrayOfStrings, set);
        std::cout << "Value found: " << *result << std::endl;
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    result = std::find(it, ite, set);
    if (result != ite)
        std::cout << "Value found using std::find: " << *result << std::endl;
    else
        std::cout << "Value not found using std::find" << std::endl;
}

static void    testMyArrayOfSets(void)
{
    std::cout << "\n----- Testing easyfind with My Array of Sets -----\n" << std::endl;

    unsigned int i = 0;

    std::cout << "Creating Array of Sets with 5 elements:" << std::endl;
    Array< std::set< int > > arrayOfSets(5); 

    std::cout << "Filling Array of Sets with values: " << std::endl;
    while (i < arrayOfSets.size())
    {
        std::set< int > innerSet;
        innerSet.insert(i + 1);
        innerSet.insert((i + 1) * 10);
        innerSet.insert((i + 1) * 100);
        arrayOfSets[i] = innerSet;
        i++;
    }
    i = 0;
    while (i < arrayOfSets.size())
    {
        printSet(arrayOfSets[i], "arrayOfSets[" + to_string_c98(i) + "] ");
        i++;
    }

    Array< std::set< int > >::Iterator it = arrayOfSets.begin();
    Array< std::set< int > >::Iterator ite = arrayOfSets.end();

    std::cout << "Creating Set of Integers with 3 elements to search for:" << std::endl;
    std::set< int > set;
    set.insert(3);
    set.insert(30);
    set.insert(300);
    printSet(set, "set ");
    
    std::cout << "\nSearching for set in the Array of Sets:" << std::endl;
    Array< std::set< int > >::Iterator result;    
    try
    {
        result = easyfind(arrayOfSets, set);
        std::cout << "Value found: ";
        printSet(*result, "result ");
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }

    result = std::find(it, ite, set);
    if (result != ite)
    {
        std::cout << "Value found using std::find: ";
        printSet(*result, "result ");
    }
    else
        std::cout << "Value not found using std::find" << std::endl;
}

/*static void    testSTLVector(void)
{
    std::cout << "\n----- Testing easyfind with STL Vector -----\n" << std::endl;

    unsigned int i = 0;

    std::cout << "Creating Vector of Integers with 5 elements:" << std::endl;
    std::vector< int > vector(5);

    std::cout << "Filling Vector of Integers with values from 1 to 5:" << std::endl;
    while (i < vector.size())
    {
        vector[i] = i + 1;
        i++;
    }
    printVector(vector, "vector ");

    std::cout << "Creating Integer to search for:" << std::endl;
    int set = 3;

    std::cout << "\nSearching for value " << set << " in the Vector of Integers:" << std::endl;
    std::vector< int >::iterator result;    
    try
    {
        result = easyfind(vector, set);
        std::cout << "Value found: " << *result << std::endl;
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
}*/

/*static void    testSTLMap(void)
{
    std::cout << "\n----- Testing easyfind with STL Map -----\n" << std::endl;

    unsigned int i = 0;

    std::cout << "Creating Map of Integers to Strings with 5 elements:" << std::endl;
    std::map< int, std::string > map;

    std::cout << "Filling Map of Integers to Strings with values:" << std::endl;
    while (i < 5)
    {
        map[i + 1] = "Value" + to_string_c98(i + 1);
        i++;
    }
    //printMap(map, "map ");

    std::cout << "Creating Integer to search for:" << std::endl;
    int set = 3;

    std::cout << "\nSearching for key " << set << " in the Map of Integers to Strings:" << std::endl;
    std::map< int, std::string >::iterator result;    
    try
    {
        result = easyfind(map, set);
        std::cout << "Value found: {" << result->first << ": \"" << result->second << "\"}" << std::endl;
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
}*/

/*static void    testSTLSet(void)
{
    std::cout << "\n----- Testing easyfind with STL Set -----\n" << std::endl;

    unsigned int i = 0;

    std::cout << "Creating Set of Integers with 5 elements:" << std::endl;
    std::set< int > set;

    std::cout << "Filling Set of Integers with values from 1 to 5:" << std::endl;
    while (i < 5)
    {
        set.insert(i + 1);
        i++;
    }
    //printSet(set, "set ");

    std::cout << "Creating Integer to search for:" << std::endl;
    int n = 3;

    std::cout << "\nSearching for value " << n << " in the Set of Integers:" << std::endl;
    std::set< int >::iterator result;    
    try
    {
        result = easyfind(set, n);
        std::cout << "Value found: " << *result << std::endl;
    }
    catch(std::invalid_argument& e)
    {
        std::cerr << e.what() << '\n';
    }
}*/

int main(void)
{
    testMyArrayOfIntegers();
    testMyArrayOfArrays();

    testMyArrayOfVectors();
    testMyArrayOfMaps();
    testMyArrayOfStrings();
    testMyArrayOfSets();

    /*testSTLVector();
    testSTLMap();
    testSTLSet();*/

    return (0);
}