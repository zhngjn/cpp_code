#ifndef BTREE_TREE_TREE_H_
#define BTREE_TREE_TREE_H_

#include <vector>

#include "tree/tree_node.h"

namespace algo
{
namespace btree
{
template <typename TreeData>
struct TreeInHeap
{   
public:
    using Node = TreeNode<TreeData>;

public:
    TreeInHeap() = default;
    // ~TreeInHeap()

private:
    void release()
    {
        if (!root_)
            return;
        
        auto node = root_;
        while (node) {
            auto left = node->left_;

        }
    }

    void releaseImpl() {}

public:
    TreeNode<TreeData>* root_{nullptr};
};

template <typename TreeData>
struct TreeInVector
{
public:
    using Node = TreeNode<TreeData>;

public:
    TreeInVector() = default;
    // ~TreeInHeap()

public:
    TreeNode<TreeData>* root_{nullptr};
};
} // namespace btree
} // namespace algo

#endif // BTREE_TREE_TREE_H_