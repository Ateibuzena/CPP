#include "PmergeMe.hpp"

static long parseInput(const std::string &arg)
{
    // check if the argument is a positive integer
    if (arg.empty() || arg[0] == '-')
        return (-1);

    // check each character to ensure it's a digit
    size_t j = 0;
    while (j < arg.length())
    {
        if (!std::isdigit(arg[j]))
            return (-2);
        j++;
    }

    // convert to integer and check range
    std::stringstream ss(arg);
    long num;
    
    ss >> num;
    if (num < 0 || num > std::numeric_limits<int>::max())
        return (-3);

    return (num);
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: No input sequence provided" << std::endl;
        std::cerr << "Usage: ./PmergeMe <positive integer sequence>" << std::endl;
        return (1);
    }
    try
    {
        /*PmergeMe pmergeMe(argc, argv);
        pmergeMe.process();*/
        PmergeMe pmergeMe;

        // parse arguments
        int i = 1;
        while (i < argc)
        {
            std::string arg = argv[i];
            long    code = parseInput(arg);
            
            switch (code)
            {
                case -1:
                    throw std::invalid_argument("Negative numbers are not allowed: " + arg);
                case -2:
                    throw std::invalid_argument("Non-integer value provided: " + arg);
                case -3:
                    throw std::out_of_range("Number out of int range: " + arg);
                default:
                    pmergeMe.addNumber(static_cast<int>(code));
            }
            i++;
        }
        pmergeMe.sort();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }

    return (0);
}