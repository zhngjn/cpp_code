#ifndef CONTAINER_TYPE_LIST_HPP_
#define CONTAINER_TYPE_LIST_HPP_

#include <string>

#include "util/stringize.h"

namespace mpl {
namespace container {

// TypeList
template <typename... Types>
struct TypeList {

};

// IsEmpty
template <typename List>
struct IsEmpty {
    constexpr static bool value = false;
};

template <>
struct IsEmpty<TypeList<>> {
    constexpr static bool value = true;
};

// Front
template <typename List>
struct FrontT;

template <typename Head, typename... Tail>
struct FrontT<TypeList<Head, Tail...>> {
    using Type = Head;
};

template <typename List>
using Front = typename FrontT<List>::Type;

// ToString
template <typename List>
struct TypeListString;

template <typename Head, typename... Tail>
struct TypeListString<TypeList<Head, Tail...>> {
    static std::string ToString() {
        return "(" + ToString2() + ")";
    }
    static std::string ToString2() {
        return util::TypeToString<Head>() + "," + TypeListString<TypeList<Tail...>>::ToString2();
    }
};

template <>
struct TypeListString<TypeList<>> {
    static std::string ToString() {
        return "()";
    }
    static std::string ToString2() {
        return "";
    }
};

// PushFront
template <typename List, typename NewType>
struct PushFrontT;

template <typename... Types, typename NewType>
struct PushFrontT<TypeList<Types...>, NewType> {
    using Type = TypeList<NewType, Types...>;
};

template <typename List, typename NewElement>
using PushFront = typename PushFrontT<List, NewElement>::Type;

// PopFront
template <typename List>
struct PopFrontT;

template <typename Head, typename... Tail>
struct PopFrontT<TypeList<Head, Tail...>> {
    using Type = TypeList<Tail...>;
};

template <typename List>
using PopFront = typename PopFrontT<List>::Type;

} // namespace container
} // namespace mpl

#endif // CONTAINER_TYPE_LIST_HPP_