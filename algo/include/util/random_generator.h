#ifndef UTIL_RANDOM_GENERATOR_H_
#define UTIL_RANDOM_GENERATOR_H_

#include <vector>
#include <random>

namespace algo
{
namespace util
{

template <typename IntType>
struct RandomIntGenerator
{
    RandomIntGenerator(unsigned seed)
        : generator_(seed)
    {}

    IntType genRandomInt(IntType min, IntType max)
    {
        std::uniform_int_distribution<IntType> distribution(min, max);
        return distribution(generator_);
    }

    std::vector<IntType> genRandomInts(IntType min, IntType max, std::size_t num)
    {
        std::vector<IntType> vec(num);
        std::uniform_int_distribution<IntType> distribution(min, max);
        for (std::size_t i = 0; i < num; i++) {
            vec[i] = distribution(generator_);
        }
        return vec;
    }

    std::default_random_engine generator_;
};

} // namespace util
} // namespace algo

#endif // UTIL_RANDOM_GENERATOR_H_