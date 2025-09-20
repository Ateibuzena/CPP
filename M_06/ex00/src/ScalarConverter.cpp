#include "ScalarConverter.hpp"

/*ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& object)
{

}

ScalarConverter&    ScalarConverter::operator=(const ScalarConverter& object)
{

}


ScalarConverter::~ScalarConverter()
{

}*/


bool    ScalarConverter::isPseudoLiteral(const std::string& literal, double& value)
{
    if (literal == "nan" || literal == "nanf")
    {
        value = std::numeric_limits<double>::quiet_NaN();
        return (true);        
    }
    else if (literal == "+inf" || literal == "+inff")
    {
        value = std::numeric_limits<double>::infinity();
        return (true);
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        value = -(std::numeric_limits<double>::infinity());
        return (true);
    }
    return (false);
}

bool    ScalarConverter::isCharLiteral(const std::string& literal, double& value)
{
    if (literal.size() == 3 && literal[0] == '\'' && literal[literal.size() - 1] == '\'')
    {
        value = static_cast<double>(literal[1]);
        return (true);
    }
    return (false);
}


void    ScalarConverter::printChar(double value, bool isPseudo)
{
    char c = static_cast<char>(value);

    std::cout << "char: ";
    
    if (isPseudo || value < 0 || value > 127)
        std::cout << "impossible";
    else if (!(std::isprint(c)))
        std::cout << "Non displayable";
    else
        std::cout
                << "'"
                << c
                << "'";
    std::cout << std::endl;
}

void    ScalarConverter::printInt(double value, bool isPseudo)
{
    int max = std::numeric_limits<int>::max();
    int min = std::numeric_limits<int>::min();

    std::cout << "int: ";
    
    if (isPseudo
            || value > static_cast<double>(max)
            || value < static_cast<double>(min))
        std::cout << "impossible";
    else
        std::cout
                << static_cast<int>(value);
    std::cout << std::endl;
}

void    ScalarConverter::printFloat(double value)
{
    std::cout << "float: ";
    
    if (std::isnan(value))
        std::cout << "nanf";
    else if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "+inff";
        else
            std::cout << "-inff";
    }
    else
        std::cout
                << std::fixed
                << std::setprecision(1)
                << static_cast<float>(value)
                << "f";
    std::cout << std::endl;
}

void    ScalarConverter::printDouble(double value)
{
    std::cout << "double: ";
    
    if (std::isnan(value))
        std::cout << "nan";
    else if (std::isinf(value))
    {
        if (value > 0)
            std::cout << "+inf";
        else
            std::cout << "-inf";
    }
    else
        std::cout
                << std::fixed
                << std::setprecision(1)
                << value;
    std::cout << std::endl;
}

void    ScalarConverter::convert(const std::string& literal)
{
    double  value = 0.0;
    bool    isPseudo = isPseudoLiteral(literal, value);

    // Check if it's a char literal
    if (!isPseudo && !isCharLiteral(literal, value))
    {
        try
        {
            std::string temp = literal;

            // Remove 'f' suffix for float literals
            if (!temp.empty() && temp[temp.size() - 1] == 'f')
                temp.resize(temp.size() - 1);

            const char* str = temp.c_str();
            char* endptr = NULL;
            
            value = strtod(str, &endptr);

            if (*endptr != '\0')
                throw std::invalid_argument("Invalid literal");
        }
        catch(...)
        {
            std::cerr << "Error: invalid literal" << std::endl;
            return ;
        }
    }
    // Print all conversions
    printChar(value, isPseudo);
    printInt(value, isPseudo);
    printFloat(value);
    printDouble(value);
}
