#pragma once

#include "searchable_bag.hpp"

class   set
{
    private:
        searchable_bag& bag;

    public:
                set() = delete;
                set(const set& object) = delete;
        set&    operator=(const set& object) = delete;

                set(searchable_bag& s_bag) : bag(s_bag)
                {

                }
        
        bool    has(int n) const
        {
            return (bag.has(n));
        }

        void    insert(int n) const
        {
            if (!(this)->has(n))
                bag.insert(n);
        }

        void    insert(int *data, int size) const
        {
            for (int i = 0; i < size; i++)
                this->insert(data[i]);
        }

        void    print(void) const
        {
            bag.print();
        }

        void    clear(void)
        {
            bag.clear();
        }

        const   searchable_bag& get_bag(void)
        {
            return (this->bag);
        }

        ~set() {}
};