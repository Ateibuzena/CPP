#include <iostream>
#include <stack>
#include <deque> 

template <typename T>
class MutantStack : public std::stack<T>
{        
    public:
                                                            MutantStack();
                                                            MutantStack(const MutantStack<T>& object);
        MutantStack<T>&                                     operator=(const MutantStack<T>& object);

                                                            ~MutantStack();

        typedef typename std::deque<T>::iterator            iterator;

        iterator                                            begin();
        iterator                                            end();

        typedef typename std::deque<T>::const_iterator      const_iterator;

        const_iterator                                      begin() const;
        const_iterator                                      end() const;
};

#include "../template/MutantStack.tpp"