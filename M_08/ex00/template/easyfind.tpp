#include "easyfind.hpp"

template <typename T, typename U>
typename T::iterator    easyfind(T& x, U n)
{

    typename T::iterator ocurrency = std::find(x.begin(), x.end(), n);

    if (ocurrency == x.end())
    {
        throw (std::invalid_argument("Value not found in this container"));
    }

    return (ocurrency);
}

template <typename T, typename U>
typename T::const_iterator   easyfind(const T& x, U n)
{

    typename T::const_iterator ocurrency = std::find(x.begin(), x.end(), n);

    if (ocurrency == x.end())
        throw (std::invalid_argument("Value not found in this container"));

    return (ocurrency);
}

// std::map<K, V> and std::set<T> require the full object to be found, not just a key or value.
// Therefore, easyfind for these containers will search for the full object.

/*template <typename K, typename V, typename U>
typename std::map<K, V>::iterator    easyfind(std::map<K, V>& m, const U &n)
{
    typename std::map<K, V>::iterator ocurrency = std::find_if(m.begin(), m.end(),
        [&n](const std::pair<const K, V>& element) { return element.first == n || element.second == n; });

    if (ocurrency == m.end())
        throw (std::invalid_argument("Value not found in this map"));

    return (ocurrency);
}*/