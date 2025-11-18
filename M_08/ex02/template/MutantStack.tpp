template <typename T>
MutantStack<T>::MutantStack()
{

}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& object)
{
    this->c = object.c;
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& object)
{
    if (this != &object)
        this->c = object.c;
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack()
{

}

template <typename T>
typename MutantStack<T>::iterator   MutantStack<T>::begin()
{
    return (this->c.begin());    
}

template <typename T>
typename MutantStack<T>::iterator   MutantStack<T>::end()
{
    return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
    return (this->c.cbegin());
}

template <typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
    return (this->c.cend());
}
