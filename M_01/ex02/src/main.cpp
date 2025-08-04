#include <iostream>

int main(void)
{
    std::string     str = "HI THIS IS BRAIN";
    std::cout << "Memory addres of the string str: " << &str << std::endl;
    std::cout << "Value of the string str: " << str << std::endl;

    std::cout << "\n------------------POINTERS----------------------\n" << std::endl;

    std::string*    strPTR = NULL;
    std::cout << "Memory addres of the string strPTR before inicialize: " << strPTR << std::endl;
    //std::cout << "Value of the string strPTR before inicialize: " << *strPTR << std::endl;
    strPTR = &str;
    std::cout << "Memory addres of the string strPTR after inicialize: " << strPTR << std::endl;
    std::cout << "Value of the string strPTR after inicialize: " << *strPTR << std::endl;

    std::cout << "\n-----------------REFERENCES-----------------------\n" << std::endl;

    //std::string&    strREF = NULL;
    std::string&    strREF = str;
    std::cout << "Memory addres of the string strREF after inicialize: " << &strREF << std::endl;
    std::cout << "Value of the string strREF after inicialize: " << strREF << std::endl;

    std::cout << "\n========== TEST DE COMPARACIONES ==========\n" << std::endl;

    std::cout << "1. ¿str == *strPTR? ";
    if (str == *strPTR)
        std::cout << "✅ true" << std::endl;
    else
        std::cout << "❌ false" << std::endl;

    std::cout << "2. ¿str == strREF? ";
    if (str == strREF)
        std::cout << "✅ true" << std::endl;
    else
        std::cout << "❌ false" << std::endl;

    std::cout << "3. ¿&str == strPTR? ";
    if (&str == strPTR)
        std::cout << "✅ true" << std::endl;
    else
        std::cout << "❌ false" << std::endl;

    std::cout << "4. ¿&str == &strREF? ";
    if (&str == &strREF)
        std::cout << "✅ true" << std::endl;
    else
        std::cout << "❌ false" << std::endl;

    std::cout << "5. ¿strPTR == &strREF? ";
    if (strPTR == &strREF)
        std::cout << "✅ true" << std::endl;
    else
        std::cout << "❌ false" << std::endl;

    std::cout << "6. ¿*strPTR == strREF? ";
    if (*strPTR == strREF)
        std::cout << "✅ true" << std::endl;
    else
        std::cout << "❌ false" << std::endl;

    std::cout << "\nAll comparisons confirm that 'str', '*strPTR', and 'strREF' refer to the same object in memory." << std::endl;
    return (0);
}