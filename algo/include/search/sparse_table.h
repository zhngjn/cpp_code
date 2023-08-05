#ifndef SEARCH_SPARSE_TABLE_H_
#define SEARCH_SPARSE_TABLE_H_

#include <type_traits>
#include <vector>
#include <cmath>

namespace algo
{
namespace search
{

template <typename RandomAccessIter, typename Selector>
class SparseTable
{
public:
    using Type = std::decay_t<decltype(*std::declval<RandomAccessIter>())>;

public:
    SparseTable(RandomAccessIter begin, RandomAccessIter end, Selector selector = Selector())
        : selector_(selector)
    {
        N_ = begin >= end ? 0 : end - begin;
        P_ = LOG2(N_) + 1;

        init(begin);
    }

    Type RMQ(std::size_t left, std::size_t right) const
    {
        std::size_t k = LOG2(right - left);
        return selector_(dp_[left][k], dp_[right - POW2(k)][k]);
    }

private:
    void init(RandomAccessIter begin)
    {
        dp_.resize(N_);
        for (std::size_t i = 0; i < N_; i++) {
            dp_[i].resize(LOG2(N_ - i) + 1);
        }

        for (std::size_t i = 0; i < N_; i++) {
            dp_[i][0] = *(begin + i);
        }

        for (std::size_t i = 1; i < P_; i++) {
            for (std::size_t s = 0; s + POW2(i) < N_ + 1; s++) {
                dp_[s][i] = selector_(dp_[s][i - 1], dp_[s + POW2(i - 1)][i - 1]);
            }
        }
    }

    inline std::size_t POW2(std::size_t i) const
    {
        return 1u << i;
    }

    inline std::size_t LOG2(std::size_t i) const
    {
        return static_cast<std::size_t>(
            std::floor(
                std::log2(static_cast<double>(i))));
    }

private:
    std::size_t N_, P_;
    Selector selector_;
    // dp_[s][l] stores the min/max elements in range [s, s + 2 ^ l)
    std::vector<std::vector<Type>> dp_;
};

} // namespace search
} // namespace algo

#endif // SEARCH_SPARSE_TABLE_H_