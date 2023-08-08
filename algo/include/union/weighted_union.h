#ifndef UNION_WEIGHTED_UNION_H_
#define UNION_WEIGHTED_UNION_H_

#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>

#include "boost/optional.hpp"

namespace algo
{
namespace disjoint_set
{

template <typename T, typename Weight>
class WeightedDisjointSet
{
public:
    using SetID = std::size_t;
    static constexpr SetID INVALID_SETID = std::numeric_limits<SetID>::max();

private:
    struct Node {
        SetID set_id_{INVALID_SETID};
        std::size_t id_{INVALID_INDEX};
        Weight weight_{};
    };

    static constexpr std::size_t INVALID_INDEX = std::numeric_limits<std::size_t>::max();

public:
    WeightedDisjointSet() = default;
    WeightedDisjointSet(const std::vector<T>& data, Weight default_weight = Weight{})
        : data_(data)
    {
        for (std::size_t i = 0; i < data_.size(); i++) {
            nodes_.insert(std::make_pair(i, Node{INVALID_SETID, i, default_weight}));
        }
    }

    /** 
     * @brief merge q to p with weight w(q->p)
     */
    bool merge(const T& p, const T& q, Weight w) 
    {
        std::size_t pi = findIndex(p);
        std::size_t qi = findIndex(q);
        if (pi == INVALID_INDEX || qi == INVALID_INDEX)
            return false;

        if (pi == qi)
            return w == Weight{};

        nodes_[qi].id_ = pi;
        nodes_[qi].weight_ = w;

        return true;
    }

    void postProcess() 
    {
        for (auto& p : nodes_) {
            if (p.second.id_ == p.first)
                p.second.set_id_ = set_count_++;
        }
    }

    SetID getSetID(const T& p) 
    {
        std::size_t pi = findIndex(p);
        if (pi == INVALID_INDEX)
            return INVALID_SETID;

        if (nodes_[pi].set_id_ != INVALID_SETID)
            return nodes_[pi].set_id_;

        // *** compress path
        compressPath(pi);

        return nodes_[pi].set_id_;
    }

    bool isJoint(const T& p, const T& q) 
    {
        SetID ps = getSetID(p);
        SetID qs = getSetID(q);
        return ps != INVALID_SETID && qs != INVALID_SETID && ps == qs;
    }

    /** 
     * @brief get weight of q->p
     */
    boost::optional<Weight> getWeightBetween(const T& p, const T& q)
    {
        std::size_t pi = findIndex(p);
        std::size_t qi = findIndex(q);
        if (pi == INVALID_INDEX || qi == INVALID_INDEX)
            return boost::none;

        if (pi == qi)
            return Weight{};

        // *** compress path
        if (nodes_[pi].set_id_ == INVALID_SETID)
            compressPath(pi);
        if (nodes_[qi].set_id_ == INVALID_SETID)
            compressPath(qi);

        // not in the same set
        if (nodes_[pi].set_id_ != nodes_[qi].set_id_)
            return boost::none;
        
        return nodes_[qi].weight_ - nodes_[pi].weight_;
    }

    std::size_t getSetCount() const 
    { 
        return set_count_; 
    }

    std::vector<T> getElementsBySetID(SetID set_id)
    {
        if (set_id >= set_count_)
            return {};
        
        std::vector<T> elements{};
        for (const auto& d : data_) {
            if (getSetID(d) == set_id) {
                elements.emplace_back(d);
            }
        }
        return elements;
    }

private:
    std::size_t findIndex(const T& p)
    {
        for (std::size_t i = 0; i < data_.size(); i++) {
            if (data_[i] == p) 
                return i;
        }
        return INVALID_INDEX;
    }

    std::size_t compressPath(std::size_t pi)
    {
        if (nodes_[pi].id_ != pi) {
            std::size_t ppi = nodes_[pi].id_;
            nodes_[pi].id_ = compressPath(ppi);
            nodes_[pi].set_id_ = nodes_[nodes_[pi].id_].set_id_;
            nodes_[pi].weight_ += nodes_[ppi].weight_;
        }
        return nodes_[pi].id_;
    }

private:
    std::vector<T> data_;
    std::unordered_map<std::size_t, Node> nodes_; 
    SetID set_count_{0};
};

} // namespace disjoint_set
} // namespace algo

#endif // UNION_WEIGHTED_UNION_H_