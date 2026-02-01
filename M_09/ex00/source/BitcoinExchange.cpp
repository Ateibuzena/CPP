#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
    : _database()
{

}

BitcoinExchange::~BitcoinExchange()
{
    _database.clear();
}

static bool isValidDate(const std::string& date)
{
    if (date.length() != 10
        || date[4] != '-'
        || date[7] != '-')
        return (false);

    int i = 0;
    while (i < 10)
    {
        if (i == 4 || i == 7)
            i++ ; // skip dashes
        if (!std::isdigit(date[i]))
            return (false);
        i++;
    }
    return (true);
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream   file(filename.c_str()); // open file in char* mode
    if (!file.is_open())
    {
        throw Exception("Error: Could not open database file: "
                        + filename
                        + "\n"
                        + "Make sure the file exists in the current directory.");
    }
    
    std::string     line; // to store each line

    std::getline(file, line); // skip header line
    if (line != "date,exchange_rate")
    {
        file.close();
        throw Exception("Error: Invalid database header line.");
    }

    while (std::getline(file, line))
    {
        if (line.empty() )
            continue ; // skip empty lines

        std::istringstream    ss(line); // convert line to stream to use >>

        std::string           date;
        char                  comma;
        float                 price;

        if (!(ss >> date >> comma >> price)
            || !isValidDate(date)
            || comma != ','
            || price < 0.0f)
            continue ; // skip invalid lines

        _database[date] = price; // insert into map
    }
    file.close();
}

float   BitcoinExchange::getExchangeRate(const std::string& date) const
{
    // find the first element not less than date
    std::map<std::string, float>::const_iterator    it = _database.lower_bound(date);

    // lower_bound returns the first element not less than key
    if (it != _database.end() && it->first == date)
    {
        return (it->second);
    }

    // date not found, get closest previous date
    if (it != _database.begin())
    {
        --it; // move to the closest previous date
        return (it->second);
    }
    return (0.0f); // date is before the first entry
}

void    BitcoinExchange::processInput(const std::string& filename) const
{
    std::ifstream   file(filename.c_str()); // open file in char* mode
    if (!file.is_open())
    {
        throw Exception("Error: Could not open input file: "
                        + filename
                        + "\n"
                        + "Make sure the file exists in the current directory.");
    }
   
    std::string     line; // to store each line

    std::getline(file, line); // skip header line

    if (line != "date | value")
    {
        file.close();
        throw Exception("Error: Invalid input header line.");
    }

    while (std::getline(file, line))
    {
        if (line.empty())
            continue ; // skip empty lines

        std::istringstream    ss(line); // convert line to stream to use >>

        std::string           date;
        char                  pipe;
        float                 value;

        if (!(ss >> date >> pipe >> value)
            || pipe != '|'
            || !isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue ;
        }
        if (value < 0.0f)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue ;
        }
        else if (value > 1000.0f)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue ;
        }

        // exchange rate is a rate on that date
        float   rate = getExchangeRate(date);

        // the result is de value multiplied by the exchange rate
        float   result = rate * value; // if rate is 0.0f, result is 0.0f

        std::cout << date
                  << " => "
                  << value
                  << " = "
                  << result
                  << std::endl;
    }
    file.close();
}
