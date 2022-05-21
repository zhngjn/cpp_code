#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

#include "boost/variant.hpp"

class PrintVisitor : public boost::static_visitor<void>
{
public:
    void operator()(const int& v)
    {
        std::cout << "int(" << v << ")" << std::endl;
    }

    void operator()(const std::string& v)
    {
        std::cout << "string(" << v << ")" << std::endl;
    }

    void operator()(const double& v)
    {
        std::cout << "double(" << v << ")" << std::endl;
    }
};

class CompareVisitor : public boost::static_visitor<bool>
{
public:
    template <typename T, typename U>
    bool operator()(const T& t, const U& u)
    {
        return toString(t) < toString(u);
    }

private:
    template <typename T>
    std::string toString(const T& t)
    {
        std::stringstream strm;
        strm << t;
        return strm.str();
    }
};

int main()
{
    using Variant = boost::variant<int, std::string, double>;

    std::vector<Variant> vec;
    vec.emplace_back(12);
    vec.emplace_back("Hello");
    vec.emplace_back(2.55);

    PrintVisitor print_visitor;
    std::for_each(vec.begin(), vec.end(), boost::apply_visitor(print_visitor));

    CompareVisitor comp_visitor;
    std::sort(vec.begin(), vec.end(), boost::apply_visitor(comp_visitor));

    std::for_each(vec.begin(), vec.end(), boost::apply_visitor(print_visitor));
}