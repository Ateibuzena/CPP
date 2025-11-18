#include "Print.hpp"

template <typename T>
void    printArray(const Array<T>& arr, const std::string& name)
{
    unsigned int i = 0;
    std::cout << "Array " << name << "with size: " << arr.size() << " and contents: [";
    while (i < arr.size())
    {
        std::cout << arr[i];
        if (i + 1 < arr.size())
            std::cout << ", ";
        i++;
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void    printVector(const std::vector<T>& vec, const std::string& name)
{
    unsigned int i = 0;
    std::cout << "Vector " << name << " with size: " << vec.size() << " and contents: [";
    while (i < vec.size())
    {
        std::cout << vec[i];
        if (i + 1 < vec.size())
            std::cout << ", ";
        i++;
    }
    std::cout << "]" << std::endl;
}

template <typename K, typename V>
void    printMap(const std::map<K, V>& mp, const std::string& name)
{
    typename std::map<K, V>::const_iterator    it = mp.begin();
    std::cout << "Map " << name << " with size: " << mp.size() << " and contents: {" ;
    while (it != mp.end())
    {
        std::cout << it->first << ": " << it->second;
        it++;
        if (it != mp.end())
            std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}

template <typename T>
void    printSet(const std::set<T>& st, const std::string& name)
{
    typename std::set<T>::const_iterator    it = st.begin();
    std::cout << "Set " << name << " with size: " << st.size() << " and contents: {";
    while (it != st.end())
    {
        std::cout << *it;
        it++;
        if (it != st.end())
            std::cout << ", ";
    }
    std::cout << "}" << std::endl;
}
