#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <type_traits>

#include "boost/tuple/tuple.hpp"
#include "boost/tuple/tuple_comparison.hpp"
#include "boost/tuple/tuple_io.hpp"

template <int Index>
struct IndexComparator
{
    template <typename Tuple1, typename Tuple2>
    bool operator()(const Tuple1& t1, const Tuple2& t2)
    {
        return boost::get<Index>(t1) < boost::get<Index>(t2);
    }
};

namespace printer1
{
template <int Index, int Size, typename Tuple>
struct TuplePrinterImpl
{
    void operator()(const Tuple& t)
    {
        TuplePrinterImpl<Index - 1, Size, Tuple>()(t);
        std::cout << "," << boost::tuples::get<Index>(t);
    }
};

template <int Size, typename Tuple>
struct TuplePrinterImpl<0, Size, Tuple>
{
    void operator()(const Tuple& t)
    {
        std::cout << boost::tuples::get<0>(t);
    }
};

template <typename Tuple>
struct TuplePrinterImpl<0, 1, Tuple>
{
    void operator()(const Tuple& t)
    {
        std::cout << boost::tuples::get<0>(t);
    }
};

template <int Size, typename Tuple>
struct TuplePrinter
{
    void operator()(const Tuple& t)
    {
        std::cout << "(";
        TuplePrinterImpl<Size - 1, Size, Tuple>()(t);
        std::cout << ")" << std::endl;
    }
};
} // namespace printer1

namespace printer2
{
template <int Index, int MaxIndex, typename Tuple>
struct TuplePrinterImpl
{
    void operator()(const Tuple& t)
    {
        std::cout << boost::tuples::get<Index>(t) << ",";
        TuplePrinterImpl<Index + 1, MaxIndex, Tuple>()(t);
    }
};

template <int MaxIndex, typename Tuple>
struct TuplePrinterImpl<0, MaxIndex, Tuple>
{
    void operator()(const Tuple& t)
    {
        std::cout << "(" << boost::tuples::get<0>(t) << ",";
        TuplePrinterImpl<1, MaxIndex, Tuple>()(t);
    }
};

template <int MaxIndex, typename Tuple>
struct TuplePrinterImpl<MaxIndex, MaxIndex, Tuple>
{
    void operator()(const Tuple& t)
    {
        std::cout << boost::tuples::get<MaxIndex>(t) << ")" << std::endl;
    }
};

template <typename Tuple>
struct TuplePrinterImpl<0, 0, Tuple>
{
    void operator()(const Tuple& t)
    {
        std::cout << "(" << boost::tuples::get<0>(t) << ")" << std::endl;
    }
};

template <int Size, typename Tuple>
struct TuplePrinter
{
    void operator()(const Tuple& t)
    {
        TuplePrinterImpl<0, Size - 1, Tuple>()(t);
    }
};
} // namespace printer2

int main()
{
    using TupleType = boost::tuple<int, std::string, double>;

    std::vector<TupleType> vec;
    vec.emplace_back(1, "summer", 1.2);
    vec.emplace_back(2, "april", 2.3);
    vec.emplace_back(3, "lotus", 0.1);

    std::sort(vec.begin(), vec.end(), IndexComparator<1>());
    
    std::for_each(vec.begin(), vec.end(), printer1::TuplePrinter<3, TupleType>());

    std::cout << "---------------------------------" << std::endl;
    std::for_each(vec.begin(), vec.end(), printer2::TuplePrinter<3, TupleType>());

    
}
