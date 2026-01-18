#pragma once
#include <string>
#include <iostream>
#include <sstream>

class bigint
{
    private:
        
        std::string         str;

        static std::string  reverseStr(const std::string& str)
        {
            std::string revStr;
            size_t      i = str.length();

            while (i > 0)
            {
                revStr.push_back(str[i - 1]);
                i--;
            }
            return (revStr);
        }
        static void         normalize(std::string& str1, std::string& str2)
        {
            size_t      len1 = str1.length();
            size_t      len2 = str2.length();

            if(len1 < len2)
                str1.append(len2 - len1, '0');
            else if(len2 < len1)
                str2.append(len1 - len2, '0');
        }

        std::string         addition(const bigint& object) const
        {
            std::string str1 = reverseStr(str);
            std::string str2 = reverseStr(object.str);

            normalize(str1, str2);

            std::string result;
            
            int         carry = 0;
            size_t      len = str1.length();
            size_t      i = 0;

            while (i < len)
            {
                int digit1 = str1[i] - '0';
                int digit2 = str2[i] - '0';

                int sum = digit1 + digit2 + carry;

                carry = sum / 10;
                result.push_back((sum % 10) + '0');
                i++;
            }

            if (carry)
                result.push_back(carry + '0');

            return (reverseStr(result));
        }

    public:

        /*-------------------------------------------------------------*/
                            bigint();
                            bigint(unsigned int num);
                            bigint(const bigint& object);
                            bigint(const std::string& s);

        bigint&             operator=(const bigint& object);

                            //~bigint();

        std::string         getStr(void) const;
                            
        bigint              operator+(const bigint& object) const;
        bigint&             operator+=(const bigint& object);

        bigint              operator++(int); //x++
        bigint&             operator++(); //++x

        bigint&             operator<<=(unsigned int n);
        bigint&             operator>>=(unsigned int n);
        bigint&             operator<<=(const bigint& object);
        bigint&             operator>>=(const bigint& object);

        bool                operator==(const bigint& object) const;
        bool                operator!=(const bigint& object) const;

        bool                operator>(const bigint& object) const;
        bool                operator<(const bigint& object) const;
        bool                operator>=(const bigint& object) const;
        bool                operator<=(const bigint& object) const;

        /*-------------------------------------------------------------*/
        bigint              operator<<(unsigned int n) const;
        bigint              operator>>(unsigned int n) const;

        bigint              operator<<(const bigint& object) const;
        bigint              operator>>(const bigint& object) const;
};

inline std::ostream&        operator<<(std::ostream& output, const bigint& object)
{
    output << object.getStr();

    return (output);
}

inline unsigned int         atoi(std::string str)
{
	std::stringstream   ss(str);
	unsigned int        res;

	ss >> res;
    
	return (res);
}