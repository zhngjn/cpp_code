#ifndef CONTAINER_TUPLE_H_
#define CONTAINER_TUPLE_H_

#include <cstdlib>
#include <type_traits>

namespace mpl
{
namespace container
{

//===================================================================
// Tuple
//===================================================================
template <typename... Types>
class Tuple;

template <typename Head, typename... Tails>
class Tuple<Head, Tails...>
{
public:
    Tuple() {}
    Tuple(const Head& head, const Tails&... tails)
        : head_(head), tails_(tails...) {}

    // ???
    template <typename Head2, typename... Tails2, 
        typename = std::enable_if_t<!std::is_same_v<std::decay_t<Head2>, Tuple<Head, Tails...>>>>
    Tuple(Head2&& head, Tails2&&... tails)
        : head_(std::forward<Head2>(head)), tails_(std::forward<Tails2>(tails)...) {}

    Tuple(const Tuple& other)
        : head_(other.head_), tails_(other.tails_) {}
    Tuple(Tuple&& other)
        : head_(std::move(other.head_)), tails_(std::move(other.tails_)) {}

    Tuple& operator=(const Tuple& other)
    {
        if (this != &other) { 
            head_ = other.head_;
            tails_ = other.tails_;
        }
        return *this;
    }
    Tuple& operator=(Tuple&& other)
    {
        if (this != &other) { 
            head_ = std::move(other.head_);
            tails_ = std::move(other.tails_);
        }
        return *this;
    }
    
    const Head& getHead() const { return head_; }
    Head& getHead() { return head_; }

    const Tuple<Tails...>& getTails() const { return tails_; }
    Tuple<Tails...>& getTails() { return tails_; }

private:
    Head head_{};
    Tuple<Tails...> tails_;
};

template <>
class Tuple<>
{

};

template <typename... Types>
auto makeTuple(Types&&... values)
{
    return Tuple<std::decay_t<Types>...>(std::forward<Types>(values)...);
}

//===================================================================
// Tuple Getter
//===================================================================
template <std::size_t INDEX>
struct TupleGetter
{
    template <typename Head, typename... Tails>
    static decltype(auto) get(const Tuple<Head, Tails...>& tpl)
    {
        return TupleGetter<INDEX - 1>::get(tpl.getTails());
    }
    
    template <typename Head, typename... Tails>
    static decltype(auto) get(Tuple<Head, Tails...>& tpl)
    {
        return TupleGetter<INDEX - 1>::get(tpl.getTails());
    }
};

template <>
struct TupleGetter<0>
{
    template <typename Head, typename... Tails>
    static decltype(auto) get(const Tuple<Head, Tails...>& tpl)
    {
        return tpl.getHead();
    }

    template <typename Head, typename... Tails>
    static decltype(auto) get(Tuple<Head, Tails...>& tpl)
    {
        return tpl.getHead();
    }
};

template <std::size_t INDEX, typename... Types>
decltype(auto) getTuple(const Tuple<Types...>& tpl)
{
    return TupleGetter<INDEX>::get(tpl);
}

template <std::size_t INDEX, typename... Types>
decltype(auto) getTuple(Tuple<Types...>& tpl)
{
    return TupleGetter<INDEX>::get(tpl);
}

//===================================================================
// Relation operators
//===================================================================
// template <typename Head, typename Tails...>
// inline bool operator==(const Tuple<Head, Tails...>& lhs, const Tuple<Head, Tails...>& rhs) 
// { 
    
// }

} // namespace container
} // namespace mpl

#endif // CONTAINER_TUPLE_H_