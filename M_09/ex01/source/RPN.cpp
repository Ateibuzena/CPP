# include "../include/RPN.hpp"

bool    RPN::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/')
        return (true);
    return (false);
}

int RPN::performOperation(int a, int b, char op)
{
    switch (op)
    {
        case '+':
            return (a + b);
        case '-':
            return (a - b);
        case '*':
            return (a * b);
        case '/':
            if (b == 0)
                throw std::runtime_error("Error: Division by zero");
            return (a / b);
        default:
            throw std::runtime_error("Error: Unknown operator");
    }
}

RPN::RPN()
    : _stack()
{

}

RPN::RPN(const RPN& object)
    : _stack(object._stack)
{

}

RPN &RPN::operator=(const RPN& object)
{
    if (this != &object)
        this->_stack = object._stack;
    return (*this);
}

RPN::~RPN()
{
    _stack.empty();
}


int RPN::evaluate(const std::string& expression)
{
    std::stringstream    ss(expression); // to parse the input
    std::string          token;

    while (ss >> token)
    {
        // verificar si el token es un operador
        if (token.find('(') != std::string::npos || token.find(')') != std::string::npos)
            throw std::runtime_error("Error: Invalid character in expression");

        // if the token is an operator
        if (token.length() == 1 && isOperator(token[0]))
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: Insufficient values in expression");

            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();

            int result = performOperation(a, b, token[0]);
            _stack.push(result);
        }
        else if (token.length() == 1 && std::isdigit(token[0]))
        {
            int value = token[0] - '0'; // convert char to int
            _stack.push(value);
        }
        else
        {
            throw std::runtime_error("Error: Invalid token '" + token + "'");
        }
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: The user input has too many values");
    return (_stack.top());
}
