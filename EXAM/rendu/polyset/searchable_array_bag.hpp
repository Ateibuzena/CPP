#pragma once

#include "array_bag.hpp"
#include "searchable_bag.hpp"

class searchable_arrya_bag : public array_bag, public searchable_bag
{
    public:
                                searchable_arrya_bag() {}
                                searchable_arrya_bag(const searchable_arrya_bag& object) : array_bag(object) {}
        searchable_arrya_bag&   operator=(const searchable_arrya_bag& object)
        {
            if (this != &object)
                array_bag::operator=(object);
            return (*this);
        }
        
        bool                    has(int n) const
        {
            for (int i = 0; i < this->size; i++)
            {
                if (this->data[i] == n)
                    return (true);
            }
        }

        ~searchable_arrya_bag() {}
};