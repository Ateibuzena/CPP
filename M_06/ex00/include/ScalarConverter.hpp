#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <iomanip>
# include <cmath>


class   ScalarConverter
{
    private:
                            ScalarConverter() = delete;
                            //ScalarConverter() = delete;  //parametrize constructor
                            ScalarConverter(const ScalarConverter& object) = delete;
        ScalarConverter&    operator=(const ScalarConverter& object) = delete;

                            ~ScalarConverter() = delete;

        /**
         * Checks if the given literal is a pseudo-literal.
         *
         * This function must:
         *  - Check if the literal is one of the pseudo-literals:
         *      - nan, nanf       -> NaN
         *      - +inf, +inff     -> positive infinity
         *      - -inf, -inff     -> negative infinity
         *  - If it matches, assign the corresponding value to 'value' (double) and return true.
         *  - If it does not match, return false.
         * @param literal The input string to check.
         * @param value Reference to store the corresponding double value if it's a pseudo-literal.
         * @return true if the literal is a pseudo-literal, false otherwise.
         */ static bool         isPseudoLiteral(const std::string& literal, double& value);

        /**
         * Checks if the given literal is a character literal.
         *
         * This function must:
         *  - Detect if the literal is a char in the format 'c' (single quotes).
         *  - If it matches, assign its ASCII value as a double to 'value' and return true.
         *  - If it does not match, return false.
         *
         * @param literal The input string to check.
         * @param value Reference to store the corresponding double value if it's a char literal.
         * @return true if the literal is a char literal, false otherwise.
         */ static bool         isCharLiteral(const std::string& literal, double& value);

        /**
         * Prints the value as a character.
         *
         * Rules:
         *  - If the value is a pseudo-literal or outside the ASCII range (0-127), print "impossible".
         *  - If the value is within the range but non-displayable, print "Non displayable".
         *  - Otherwise, print the character in single quotes.
         *
         * @param value The value to convert to char.
         * @param isPseudo True if the value is a pseudo-literal (nan, inf, etc.).
         */ static void         printChar(double value, bool isPseudo);

        /**
         * Prints the value as an integer.
         *
         * Rules:
         *  - If the value is a pseudo-literal or outside the int range, print "impossible".
         *  - Otherwise, print the value as an integer.
         *
         * @param value The value to convert to int.
         * @param isPseudo True if the value is a pseudo-literal (nan, inf, etc.).
         */ static void         printInt(double value, bool isPseudo);
        
        /**
         * Prints the value as a float.
         *
         * Rules:
         *  - If the value is NaN, print "nanf".
         *  - If the value is positive or negative infinity, print "+inff" or "-inff".
         *  - Otherwise, print the value with one decimal and the 'f' suffix.
         *
         * @param value The value to convert to float.
         */ static void         printFloat(double value);

        /**
         * Prints the value as a double.
         *
         * Rules:
         *  - If the value is NaN, print "nan".
         *  - If the value is positive or negative infinity, print "+inf" or "-inf".
         *  - Otherwise, print the value with one decimal.
         *
         * @param value The value to convert to double.
         */ static void         printDouble(double value);

    public:

        /**
         * Converts the given literal to char, int, float, and double, printing each.
         *
         * The function handles:
         *  - Char literals ('a', 'c', etc.)
         *  - Integer and floating point literals (decimal notation)
         *  - Pseudo-literals (nan, nanf, +inf, +inff, -inf, -inff)
         *
         * @param literal The input string representing a C++ literal.
         */ static void         convert(const std::string& literal);
};

#endif