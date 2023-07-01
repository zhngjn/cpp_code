#pragma once

#include <vector>
#include <string>
#include <sstream>

namespace util
{

template <typename T>
std::string toString(const std::vector<T>& vec)
{
    if (vec.empty())
        return "[]";

    std::stringstream sstrm;
    sstrm << "[";
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        sstrm << vec[i];
        if (i != vec.size() - 1)
            sstrm << ",";
    }
    sstrm << "]";
    return sstrm.str();
}

template <typename T>
std::string toString(const std::vector<std::vector<T>>& vec_vec)
{
    if (vec_vec.empty())
        return "[]";

    std::stringstream sstrm;
    sstrm << "[";
    for (std::size_t i = 0; i < vec_vec.size(); i++)
    {
        sstrm << toString(vec_vec[i]);
        if (i != vec_vec.size() - 1)
            sstrm << ",";
    }
    sstrm << "]";
    return sstrm.str();
}

} // namespace util