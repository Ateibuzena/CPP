#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main(void)
{
    Base* base = generate();

    identify(base);
    identify(*base);
}