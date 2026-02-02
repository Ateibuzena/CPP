#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack> // for rpn we need a stack because of its LIFO property
# include <string>
# include <sstream> // for stringstream to parse the input, allow split by space
# include <stdexcept> // for standard exceptions

class RPN
{
    private:
        std::stack<int> _stack;

        bool            isOperator(char c);
        int             performOperation(int a, int b, char op);

    public:
                        RPN();
                        RPN(const RPN& object);
                        RPN &operator=(const RPN& object);
                        ~RPN();

        int             evaluate(const std::string& expression);
};

#endif