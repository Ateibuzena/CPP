#include "../include/PmergeMe.hpp"

// ========== ORTHODOX CANONICAL FORM ==========

PmergeMe::PmergeMe()
    :   _vec(),
        _deq()
{

}

PmergeMe::PmergeMe(const PmergeMe &object)
    :   _vec(object._vec),
        _deq(object._deq)
{

}

PmergeMe&   PmergeMe::operator=(const PmergeMe &object)
{
    if (this != &object)
    {
        _vec = object._vec;
        _deq = object._deq;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{
    _vec.clear();
    _deq.clear();
}

// ========== PUBLIC METHODS ==========

void    PmergeMe::addNumber(int number)
{
    _vec.push_back(number);
    _deq.push_back(number);
}

void    PmergeMe::sort()
{
    // Sort vector
    struct timeval start_vec, end_vec;

    gettimeofday(&start_vec, NULL);
    mergeInsertSortVector(_vec, 0, _vec.size() - 1);
    gettimeofday(&end_vec, NULL);

    double time_vec = (end_vec.tv_sec - start_vec.tv_sec) * 1000000.0; // convert seconds to microseconds
    time_vec += (end_vec.tv_usec - start_vec.tv_usec); // add microseconds difference

    // Sort deque
    struct timeval start_deq, end_deq;

    gettimeofday(&start_deq, NULL);
    mergeInsertSortDeque(_deq, 0, _deq.size() - 1);
    gettimeofday(&end_deq, NULL);

    double time_deq = (end_deq.tv_sec - start_deq.tv_sec) * 1000000.0; // convert seconds to microseconds
    time_deq += (end_deq.tv_usec - start_deq.tv_usec); //

    // display results
    display();

    std::cout << "Time to process a range of "
            << _vec.size()
            << " elements with std::vector : "
            << std::fixed // use fixed-point notation because scientific notation is not suitable for time display
            << std::setprecision(5) // set precision to 5 decimal places
            << time_vec // time to sort in microseconds
            << " us" // microseconds
            << std::endl;

    std::cout << "Time to process a range of "
            << _deq.size()
            << " elements with std::deque : "
            << std::fixed // use fixed-point notation because scientific notation is not suitable for time display
            << std::setprecision(5) // set precision to 5 decimal places
            << time_deq // time to sort in microseconds
            << " us" // microseconds
            << std::endl;
}

void    PmergeMe::display() const
{
    std::cout << "Before: ";

    size_t i = 0;
    while (i < _vec.size() && i < 5)
    {
        std::cout << _vec[i] << " ";
        i++;
    }
    if (_vec.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;

    std::cout << "After: ";
    i = 0;
    while (i < _vec.size() && i < 5)
    {
        std::cout << _vec[i] << " ";
        i++;
    }
    if (_vec.size() > 5)
        std::cout << "[...]";
    std::cout << std::endl;
}

// ========== PRIVATE METHODS - FORD-JOHNSON ALGORITHM ==========

// For n elements and threshold t
// the deepth of recursion is d = log2(n/t)
// the number of calls is 2^(d + 1) - 1

void    PmergeMe::mergeInsertSortVector(std::vector<int> &arr, int left, int right)
{
    // we order a subarray arr[left..right] 
    // if the subarray has THRESHOLD or less elements, use insertion sort
    if (right - left <= THRESHOLD) // THRESHOLD is empirical threshold for switching to insertion sort
    {
        insertionSort(arr, left, right); // is quick enough for small arrays because less comparisons and swaps
        return ;
    }

    int mid = left + (right - left) / 2; // find the midpoint skipping potential overflow
    mergeInsertSortVector(arr, left, mid); // sort the left half
    mergeInsertSortVector(arr, mid + 1, right); // sort the right half
    merge(arr, left, mid, right); // merge the sorted halves
}

void    PmergeMe::mergeInsertSortDeque(std::deque<int> &arr, int left, int right)
{
    if (right - left <= THRESHOLD) // threshold for switching to insertion sort
    {
        insertionSort(arr, left, right);
        return ;
    }

    int mid = left + (right - left) / 2; // find the midpoint
    mergeInsertSortDeque(arr, left, mid); // sort the left half
    mergeInsertSortDeque(arr, mid + 1, right); // sort the right half
    merge(arr, left, mid, right); // merge the sorted halves
}

template <typename Container>
void    PmergeMe::insertionSort(Container &container, int left, int right)
{
    int i = left + 1; // start from the second element
    while (i <= right) // go through each element
    {
        int key = container[i]; // current element to be inserted
        int j = i - 1; // index of the last sorted element

        // move elements of container[left..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= left && container[j] > key)
        {
            container[j + 1] = container[j];
            j--;
        }
        container[j + 1] = key; // insert the key at its correct position
        i++;
    }
}

template <typename Container>
void    PmergeMe::merge(Container &container, int left, int mid, int right)
{
    Container   temp;

    int i =     left; // starting index for left subarray
    int j =     mid + 1; // starting index for right subarray

    // Compare elements from both subarrays and merge them in sorted order
    while (i <= mid && j <= right)
    {
        if (container[i] <= container[j])
        {
            temp.push_back(container[i]);
            i++;
        }
        else
        {
            temp.push_back(container[j]);
            j++;
        }
    }

    // Copy any remaining elements from the left subarray
    while (i <= mid)
    {
        temp.push_back(container[i]);
        i++;
    }

    // Copy any remaining elements from the right subarray
    while (j <= right)
    {
        temp.push_back(container[j]);
        j++;
    }

    // Copy the merged elements back into the original container
    size_t k = 0;
    while (k < temp.size())
    {
        container[left + k] = temp[k]; // place back into original container
        k++;
    }
}

double    PmergeMe::getTime()
{
    struct timeval  time;
    
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000000.0 + time.tv_usec); // return time in microseconds
}
