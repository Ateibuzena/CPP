#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <sstream>
# include <stdexcept>
# include <iterator>
# include <algorithm>
# include <cstddef>
# include <cmath>

template <typename T>
class Array
{
    private:

        const unsigned int                              _size;
        T*                                              _data;
    
    public:
    
                                                        Array();
                                                        Array(unsigned int sizeValue);
                                                        Array(const Array& object);
        Array&                                          operator=(const Array& object);

                                                        ~Array();

        unsigned int                                    size(void) const;
        const T&                                        operator[](unsigned int i) const;

        T&                                              operator[](unsigned int i);

        bool                                            operator==(const Array& object) const;
        bool                                            operator!=(const Array& object) const;

        class                                           Iterator
        {
            private:

                T*                                      _ptr;

            public:

                typedef std::random_access_iterator_tag iterator_category;
                typedef T                               value_type;
                typedef std::ptrdiff_t                  difference_type;
                typedef T*                              pointer;
                typedef T&                              reference;
                
                                                        Iterator();
                                                        Iterator(T* ptr);
                Iterator&                               operator=(const Iterator& object);

                const T&                                operator*() const;
                reference                               operator*();

                const Iterator&                         operator++();
                Iterator                                operator++(int);

                bool                                    operator!=(const Iterator& object) const;
                bool                                    operator==(const Iterator& object) const;

                difference_type                         operator-(const Iterator& object) const;
                
                Iterator                                operator+(difference_type n) const;
                Iterator                                operator-(difference_type n) const;
                const Iterator&                         operator+=(difference_type n);
                const Iterator&                         operator-=(difference_type n);

                bool                                    operator<(const Iterator& object) const;
                bool                                    operator<=(const Iterator& object) const;
                bool                                    operator>(const Iterator& object) const;
                bool                                    operator>=(const Iterator& object) const;
        };      

        Iterator                                        begin();
        Iterator                                        end();

        const Iterator                                  begin() const;
        const Iterator                                  end() const;

        typedef Iterator                                iterator;
        typedef const Iterator                          const_iterator;
};

template <typename T>
std::ostream&                                           operator<<(std::ostream& fd, const Array<T>& object);

std::string                                             to_string_c98(int value);

# include "../template/Array.tpp"
# include "../template/Iterator.tpp"
# include "../template/Utils.tpp"

#endif
           