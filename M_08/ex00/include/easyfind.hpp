#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <stdexcept>

template <typename T, typename U>
typename T::iterator            easyfind(T& x, U n);

template <typename T, typename U>
typename T::const_iterator      easyfind(const T& x, U n);

# include "../template/easyfind.tpp"

#endif