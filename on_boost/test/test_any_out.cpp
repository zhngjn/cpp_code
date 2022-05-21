#include <vector>
#include <iostream>

#include "any_out.h"

struct A
{
    int x;

    A(int xx) : x(xx) {} 
     
    friend std::ostream& operator<<(std::ostream& ostrm, const A& a)
    {
        return ostrm << "A(" << a.x << ")";
    }
};

int main()
{
    std::vector<AnyOut> vec;

    vec.emplace_back(12);
    vec.emplace_back(std::string("abc"));
    vec.emplace_back(A(3));

    for (const auto& v : vec)
        std::cout << v << std::endl;
}