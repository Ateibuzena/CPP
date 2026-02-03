#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream> // std::cout, std::cerr
# include <sstream> // std::stringstream
# include <string> // std::string
# include <cctype> // std::isdigit
# include <stdexcept> // std::invalid_argument, std::out_of_range
# include <sys/time.h> // gettimeofday to show difference bewteen containers
# include <limits> // std::numeric_limits to validate the number can be stored in an int
# include <vector> // std::vector
# include <deque> // std::deque
# include <iomanip> // std::setprecision to show time with precision
# define THRESHOLD 10 // threshold to switch to insertion sort

class PmergeMe
{
    private:
        std::vector<int>    _vec;
        std::deque<int>     _deq;

        // Ford-Johnson merge-insert sort implementation
        void                mergeInsertSortVector(std::vector<int> &arr, int left, int right);
        void                mergeInsertSortDeque(std::deque<int> &arr, int left, int right);

        // Helper functions for the algorithm
        template <typename Container>
        void                insertionSort(Container &container, int left, int right);

        template <typename Container>
        void                merge(Container &container, int left, int mid, int right);

        // Time measurement
        double              getTime();

    public:
                            PmergeMe();
                            PmergeMe(const PmergeMe &object);
        PmergeMe&           operator=(const PmergeMe &object);
                            ~PmergeMe();

        void                addNumber(int number);
        void                sort();
        void                display() const;
};

#endif