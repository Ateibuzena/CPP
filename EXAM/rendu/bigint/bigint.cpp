#include "bigint.hpp"

/*-------------------------------------------------------------*/
bigint::bigint()
    : str("0")
{

}

bigint::bigint(unsigned int num)
{
    std::stringstream   ss;

    ss << num;
    str = ss.str();
}

bigint::bigint(const bigint& object)
    : str(object.str)
{

}

bigint::bigint(const std::string& s)
    : str(s)
{

}

bigint&             bigint::operator=(const bigint& object)
{
    if (this != &object)
        str = object.str;
    
    return (*this);
}

//~bigint()

std::string bigint::getStr(void) const
{
    return (str);
}

bigint  bigint::operator+(const bigint& object) const
{
    return (bigint(addition(object)));
}

bigint& bigint::operator+=(const bigint& object)
{
    (*this) = (*this) + object;

    return ((*this));
}

bigint  bigint::operator++(int) //x++
{
    bigint  temp(*this);
    (*this) = (*this) + bigint(1);
    return (temp);
}

bigint& bigint::operator++() //++x
{
    (*this) = (*this) + bigint(1);
    return (*this);
}

bigint& bigint::operator<<=(unsigned int n)
{
    (*this) = (*this) << n;
    return (*this);
}

bigint& bigint::operator>>=(unsigned int n)
{
    (*this) = (*this) >> n;
    return (*this);
}

bigint& bigint::operator<<=(const bigint& object)
{
    (*this) = (*this) << atoi(object.str);
    return (*this);
}

bigint& bigint::operator>>=(const bigint& object)
{
    (*this) = (*this) >> atoi(object.str);
    return (*this);
}

bool    bigint::operator==(const bigint& object) const
{
    if (str == object.str)
        return (true);
    return (false);
}

bool    bigint::operator!=(const bigint& object) const
{
    if (str == object.str)
        return (false);
    return (true);
}

bool    bigint::operator>(const bigint& object) const
{
    std::string     str1 = str;
    std::string     str2 = object.str;
    size_t          len1 = str1.length();
    size_t          len2 = str2.length();

    if (len1 != len2)
        return (len1 > len2);
    return (str1 > str2);
}

bool    bigint::operator<(const bigint& object) const
{
    std::string     str1 = str;
    std::string     str2 = object.str;
    size_t          len1 = str1.length();
    size_t          len2 = str2.length();

    if (len1 != len2)
        return (len1 < len2);
    return (str1 < str2);
}

bool    bigint::operator>=(const bigint& object) const
{
    return ((((*this) > object) || (*this == object)));
}

bool    bigint::operator<=(const bigint& object) const
{
    return ((((*this) < object) || (*this == object)));
}

/*-------------------------------------------------------------*/

bigint  bigint::operator<<(unsigned int n) const
{
    if (str == "0")
        return (*this);

    std::string result = str + std::string(n, '0');
    return (bigint(result));
}

bigint  bigint::operator>>(unsigned int n) const
{
    if (n >= str.length())
        return (bigint(0));

    std::string  result = str.substr(0, str.length() - n);
    return (bigint(result));
}

bigint  bigint::operator<<(const bigint& object) const
{
    bigint  temp;
    temp = (*this) << atoi(object.str);
    return (temp);
}

bigint  bigint::operator>>(const bigint& object) const
{
    bigint  temp;
    temp = (*this) >> atoi(object.str);
    return (temp);
}
