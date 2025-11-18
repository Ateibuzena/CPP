#include "Array.hpp"

template <typename T>
std::ostream&   operator<<(std::ostream& fd, const Array<T>& object)
{
    fd << "[";

    unsigned int i = 0;
    while (i < object.size())
    {
        fd << object[i];
        if (i + 1 < object.size())
            fd << ", ";
        i++;
    }
    fd << "]";
    
    return (fd);
}

std::string to_string_c98(int value)
{
    std::ostringstream  oss;

    oss << value;

    return (oss.str());
}
