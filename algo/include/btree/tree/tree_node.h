#ifndef BTREE_TREE_TREE_NODE_H_
#define BTREE_TREE_TREE_NODE_H_

namespace algo
{
namespace btree
{
template <typename TreeData>
struct TreeNode
{
    TreeNode() = default;
    TreeNode(const TreeData& data, TreeNode* left, TreeNode* right)
        : data_(data), left_(left), right_(right) {}

    TreeData data_{};
    TreeNode<TreeData>* left_{nullptr};
    TreeNode<TreeData>* right_{nullptr};
};

} // namespace btree
} // namespace algo

#endif // BTREE_TREE_TREE_NODE_H_