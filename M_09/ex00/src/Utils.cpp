#include "BitcoinExchange.hpp"

std::string trim(const std::string& s)
{
    std::string     result = "";

    size_t          start = 0;
    unsigned char   c = static_cast<unsigned char>(s[0]);
    while (start < s.size() && isspace(c))
    {
        start++;
        c = static_cast<unsigned char>(s[start]);
    }

    if (start == s.size())
        return (result);
    
    size_t          end = s.size() - 1;
    c = static_cast<unsigned char>(s[end]);
    while (end > start && isspace(c))
    {
        end--;
        c = static_cast<unsigned char>(s[end]);
    }

    result = s.substr(start, end - start + 1);
    
    return (result);
}

const std::map<int, int>  getMapMonthDays(void)
{
    const std::map<int, int>    map = 
    {
        std::make_pair(1, 31),
        std::make_pair(2, 28),
        std::make_pair(3, 31),
        std::make_pair(4, 30),
        std::make_pair(5, 31),
        std::make_pair(6, 30),
        std::make_pair(7, 31),
        std::make_pair(8, 31),
        std::make_pair(9, 30),
        std::make_pair(10, 31),
        std::make_pair(11, 30),
        std::make_pair(12, 31)
    };

    return (map);
}
