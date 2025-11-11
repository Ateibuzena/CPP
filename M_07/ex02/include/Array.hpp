#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include <cmath>

template <typename T>
class Array
{
    private:

        const unsigned int  _size;
        T*                  _data;
    
    public:
    
                                Array();
                                Array(unsigned int sizeValue);
                                Array(const Array& object);
        Array&                  operator=(const Array& object);

                                ~Array();

        unsigned int            size(void) const;
        const T&                operator[](unsigned int i) const;

        T&                      operator[](unsigned int i);

        class                   Iterator
        {
            private:

                T*          _ptr;

            public:
                
                                Iterator(T* ptr);
                Iterator&       operator=(const Iterator& object);

                const T&        operator*() const;
                T&              operator*();

                const Iterator& operator++();
                Iterator        operator++(int);

                bool            operator!=(const Iterator& object) const;
                bool            operator==(const Iterator& object) const;
        };

        Iterator                begin();
        Iterator                end();

        const Iterator          begin() const;
        const Iterator          end() const;
};

template <typename T>
std::ostream&                   operator<<(std::ostream& fd, const Array<T>& object);

template <typename T>
void                            printArray(const Array<T>& arr, const std::string& name);

int                             test(void);

# include "../template/Array.tpp"
# include "../template/Iterator.tpp"
# include "../template/Utils.tpp"

#endif
           