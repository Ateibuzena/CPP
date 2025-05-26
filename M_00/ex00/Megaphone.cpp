#include <iostream> 
#include <cctype>
#include <string>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::string str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

        std::cout << str << std::endl;
        return (0);
    }
    int i = 1;

    while (i < argc)
    {
        std::string str = argv[i];
        size_t j = 0;

        while (j < str.length())
        {
            std::cout << static_cast<char>(std::toupper(str[j]));
            j++;
        }
        std::cout << " ";
        i++;
    }
    std::cout << std::endl;
    return (0);
}