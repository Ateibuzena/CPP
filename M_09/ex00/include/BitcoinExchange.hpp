#pragma once

#include <map>
#include <iostream>
#include <exception>

class BitcoinExchange
{
    private:

        std::map<std::string, double>   _bitcoinPrices;
      
        bool                            isValidDate(const std::string& date);
        bool                            isValidValue(const std::string& valueStr, double& out);
        bool                            isLeapYear(int year);
    
        bool                            getPriceForDate(const std::string& date, double& price);

    public:

                                        BitcoinExchange();
                                        BitcoinExchange(const std::string& filePath = "data.csv");
                                        BitcoinExchange(const BitcoinExchange& object);
        BitcoinExchange&                operator=(const BitcoinExchange& object);

                                        ~BitcoinExchange();

        void                            loadDatabase(const std::string& path);


        void                            processInputFile(const std::string& path);
};

std::string                             trim(const std::string& s);
const std::map<int, int>                getMapMonthDays(void);
