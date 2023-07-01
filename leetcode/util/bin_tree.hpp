#pragma once

#include <iostream>
#include <unordered_set>
#include <limits>
#include <queue>
#include <initializer_list>

namespace util
{
constexpr int InvalidTreeNodeValue = std::numeric_limits<int>::min();

template <typename TreeNode>
TreeNode* createTreeInHeap(const std::vector<int>& node_values)
{
    struct NodeInfo
    {
        TreeNode* node_;
        int idx_;
    };

    if (node_values.empty() || node_values[0] == InvalidTreeNodeValue)
        return nullptr;

    std::queue<NodeInfo> Q;
    TreeNode* root = new TreeNode(node_values[0]);
    Q.push({root, 0});
    while (!Q.empty())
    {
        NodeInfo cur = Q.front();
        Q.pop();

        int left_idx = 2 * cur.idx_ + 1;
        if (left_idx < node_values.size())
        {
            if (node_values[left_idx] != InvalidTreeNodeValue)
            {
                TreeNode* left = new TreeNode(node_values[left_idx]);
                cur.node_->left = left;
                Q.push({left, left_idx});
            }
        }

        int right_idx = left_idx + 1;
        if (right_idx < node_values.size())
        {
            if (node_values[right_idx] != InvalidTreeNodeValue)
            {
                TreeNode* right = new TreeNode(node_values[right_idx]);
                cur.node_->right = right;
                Q.push({right, right_idx});
            }
        }
    }
    
    return root;
}

template <typename TreeNode>
TreeNode* createTreeInHeap(std::initializer_list<int> node_values)
{
    std::vector<int> node_values_vec(node_values);
    return createTreeInHeap<TreeNode>(node_values_vec);
}

template <typename TreeNode>
void printTree_preOrder_impl(TreeNode* root)
{
    if (!root)
        return;
    std::cout << root->val << ",";
    printTree_preOrder_impl(root->left);
    printTree_preOrder_impl(root->right);
}

template <typename TreeNode>
void printTree_preOrder(TreeNode* root)
{
    printTree_preOrder_impl<TreeNode>(root);
    std::cout << std::endl;
}

} // namespace util