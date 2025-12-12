#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
    :   _bitcoinPrices(NULL, NULL)
{

}

BitcoinExchange::BitcoinExchange(const std::string& filePath)
    :   _bitcoinPrices(NULL, NULL)
{
    try
    {
        // Cargar csv
        loadDatabase(filePath);

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& object)
    :   _bitcoinPrices(object._bitcoinPrices)
{

}

BitcoinExchange&    BitcoinExchange::operator=(const BitcoinExchange& object)
{
    if (this != &object)
    {
        _bitcoinPrices = object._bitcoinPrices;
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{

}

void    BitcoinExchange::loadDatabase(const std::string& path)
{

}

bool    BitcoinExchange::isValidDate(const std::string& date)
{
    // formato YYYY-MM-DD (10 chars)
    if (date.size() != 10)
        return (false);

    // comprobar posiciones de guiones
    if (date[4] != '-' || date[7] != '-')
        return (false);
    
    // comprobar que los demás son digitos
    size_t i = 0;
    while (i < date.size())
    {
        if (i == 4 || i == 7)
            continue ;
        
        unsigned char c = static_cast<unsigned char>(date[i]);
        if (!isdigit(c))
            return (false);
        
        i++;
    }

    // convertir a numero
    std::string     temp = date.substr(0, 4);
    int year = std::atoi(temp.c_str());

    std::string     temp = date.substr(5, 2);
    int month = std::atoi(temp.c_str());

    std::string     temp = date.substr(8, 2);
    int day = std::atoi(temp.c_str());

    // chequear año
    if (year <= 0)
        return (false);
    
    // chequear month
    if (month < 1 || month > 12)
        return (false);
    
    // obtener cantidad de dias segun el mes
    const std::map<int, int>    mDays = getMapMonthDays();
    int maxD = mDays.find(month)->second;

    // ajustar la cantidad de dias si el año es bisiesto
    if (month == 2 && isLeapYear(year))
        maxD = 29;
    
    // chequear día según mes
    if (day < 1 || day > maxD)
        return (false);
    
    // todo bien
    return (true);
}

bool    BitcoinExchange::isValidValue(const std::string& valueStr, double& out)
{
    // limppiamos de espacios
    std::string str = trim(valueStr);
    if (str.empty())
        return (false);

    // check characters: digits, one dot, optional leading +, maybe decimal
    int     dotCount = 0;
    int     digitCount = 0;
    size_t  i = 0;

    while (i < str.size())
    {
        char c = str[i];

        // check one dot
        if (c == '.')
        {
            dotCount = dotCount + 1;
            if (dotCount > 1)
                return (false);
        }

        // check optional leading +
        else if (c == '+' || c == '-')
        {
            if (i != 0)
                return (false);
            if (c == '-')
                return (false);
        }

        // check digits
        else if (!)
        
        i++;
    }
}

bool    BitcoinExchange::isLeapYear(int year)
{
    if (year % 400 == 0)
        return (true);
    if (year % 100 == 0)
        return (false);
    if (year % 4 == 0)
        return (true);
    else
        return (false);
}


bool    BitcoinExchange::getPriceForDate(const std::string& date, double& price)
{

}


void    BitcoinExchange::processInputFile(const std::string& path)
{

}
