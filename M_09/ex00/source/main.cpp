#include "../include/BitcoinExchange.hpp"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return (1);
    }

    BitcoinExchange   bitcoinExchange;

    try
    {
        bitcoinExchange.loadDatabase("data.csv");
        bitcoinExchange.processInput(argv[1]);
    }
    catch (const BitcoinExchange::Exception& e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
