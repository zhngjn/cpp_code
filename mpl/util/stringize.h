#ifndef UTIL_STRINGIZE_HPP_
#define UTIL_STRINGIZE_HPP_

#include <string>
#include <typeinfo>

namespace mpl {
namespace util {

template <typename T>
std::string TypeToString() {
    return typeid(T).name();
}

} // namespace util
} // namespace mpl

#endif // UTIL_STRINGIZE_HPP_