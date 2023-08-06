#ifndef UNION_UNION_H_
#define UNION_UNION_H_

#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>

namespace algo
{
namespace disjoint_set
{

template <typename T>
class DisjointSet
{
public:
    using SetID = std::size_t;
    static constexpr SetID INVALID_SETID = std::numeric_limits<SetID>::max();

private:
    struct Node {
        SetID set_id_{INVALID_SETID};
        std::size_t id_{INVALID_INDEX};
        std::size_t count_{0};
    };

    static constexpr std::size_t INVALID_INDEX = std::numeric_limits<std::size_t>::max();

public:
    DisjointSet() = default;
    DisjointSet(const std::vector<T>& data)
        : data_(data)
    {
        for (std::size_t i = 0; i < data_.size(); i++) {
            nodes_.insert(std::make_pair(i, Node{INVALID_SETID, i, 1}));
        }
    }

    bool merge(const T& p, const T& q) 
    {
        if (p == q)
            return true;

        std::size_t pi = INVALID_INDEX, qi = INVALID_INDEX;
        std::size_t found_num = 0;
        for (std::size_t i = 0; i < data_.size(); i++) {
            if (data_[i] == p) { pi = i; found_num++; }
            else if (data_[i] == q) { qi = i; found_num++; }
            if (found_num == 2) break;
        }
        if (found_num != 2)
            return false;

        while (nodes_[pi].id_ != pi) pi = nodes_[pi].id_;
        while (nodes_[qi].id_ != qi) qi = nodes_[qi].id_;
        if (nodes_[pi].count_ < nodes_[qi].count_) {
            nodes_[pi].id_ = qi;
            nodes_[qi].count_ += nodes_[pi].count_;
        }
        else {
            nodes_[qi].id_ = pi;
            nodes_[pi].count_ += nodes_[qi].count_;
        }
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
        const auto it = std::find(data_.begin(), data_.end(), p);
        if (it == data_.end())
            return INVALID_SETID;

        std::size_t pi = static_cast<std::size_t>(it - data_.begin());
        if (nodes_[pi].set_id_ != INVALID_SETID)
            return nodes_[pi].set_id_;

        // *** compress path
        std::size_t root = pi;
        while (nodes_[root].id_ != root) 
            root = nodes_[root].id_;
        SetID set_id = nodes_[root].set_id_;
        std::size_t i = pi, j;
        while (i != root) {
            j = nodes_[i].id_;
            nodes_[i].id_ = root;
            nodes_[i].set_id_ = set_id;
            i = j;
        }

        return set_id;
    }

    bool isJoint(const T& p, const T& q) 
    {
        if (p == q) 
            return true;

        SetID ps = getSetID(p);
        SetID qs = getSetID(q);
        return ps != INVALID_SETID && qs != INVALID_SETID && ps == qs;
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
    std::vector<T> data_;
    std::unordered_map<std::size_t, Node> nodes_; 
    SetID set_count_{0};
};

} // namespace disjoint_set
} // namespace algo

#endif // UNION_UNION_H_