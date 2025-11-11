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

template <typename T>
void    printArray(const Array<T>& arr, const std::string& name)
{
    std::cout << name << " (" << arr.size() << "): " << arr << std::endl;
}
