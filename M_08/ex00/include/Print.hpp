#ifndef PRINT_HPP
#define PRINT_HPP

# include <iostream>
# include <string>
# include <map>
# include <set>
# include <vector>
# include "Array.hpp"


template <typename T>
void    printArray(const Array<T>& arr, const std::string& name);

template <typename T>
void    printVector(const std::vector<T>& vec, const std::string& name);

template <typename K, typename V>
void    printMap(const std::map<K, V>& mp, const std::string& name);

template <typename T>
void    printSet(const std::set<T>& st, const std::string& name);

# include "../template/Print.tpp"

#endif
