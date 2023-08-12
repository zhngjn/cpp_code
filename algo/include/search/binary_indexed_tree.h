#ifndef SEARCH_BINARY_INDEXED_TREE_H_
#define SEARCH_BINARY_INDEXED_TREE_H_

#include <vector>
#include <cstdint>

namespace algo
{
namespace search
{

template <typename T, typename Accumulator>
class BinaryIndexedTree
{
public:
    BinaryIndexedTree(const std::vector<T>& data, Accumulator acc = Accumulator())
        : acc_(acc)
    {
        init(data);
    }

    void add(std::size_t i, const T& inc)
    {
        i++;
        while (i < tree_.size()) {
            tree_[i] = acc_(tree_[i], inc);
            i += lowestBit(i);
        }
    }

    /**
     * @brief return the sum of range [0, i]
     * 
     */
    T sum(std::size_t i) {
        T val{};
        i++;
        while (i > 0) {
            val = acc_(val, tree_[i]);
            i -= lowestBit(i);
        }
        return val;
    }

private:
    void init(const std::vector<T>& data)
    {
        // tree_[0] is not used
        tree_.resize(data.size() + 1);

        for (std::size_t i = 0; i < data.size(); i++) {
            add(i, data[i]);
        }
    }

private:
    static std::size_t lowestBit(std::size_t x)
    {
        std::int64_t y = static_cast<std::int64_t>(x);
        return static_cast<std::size_t>(y & (-y));
    }

private:
    std::vector<T> tree_;
    Accumulator acc_;
};

} // namespace search
} // namespace algo

#endif // SEARCH_BINARY_INDEXED_TREE_H_