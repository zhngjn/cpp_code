#include <utility>
#include <iostream>
#include <cstdlib>

#include "util/bin_tree.hpp"

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    bool isBalanced(TreeNode* root) 
    {
        return dfs(root).first;
    }

private:
    std::pair<bool, int> dfs(TreeNode* node)
    {
        if (!node)
            return std::make_pair(true, 0);
        
        const auto left_res = dfs(node->left);
        const auto right_res = dfs(node->right);

        bool is_balanced = left_res.first 
            && right_res.first 
            && std::abs(left_res.second - right_res.second) < 2;
        
        return std::make_pair(is_balanced, std::max(left_res.second, right_res.second) + 1);
    }
};

int main()
{
    Solution s;

    {
        TreeNode* root = util::createTreeInHeap<TreeNode>({3,9,20,util::InvalidTreeNodeValue,util::InvalidTreeNodeValue,15,7});
        std::cout << s.isBalanced(root) << std::endl;
    }
    {
        TreeNode* root = util::createTreeInHeap<TreeNode>({1,2,2,3,3,util::InvalidTreeNodeValue,util::InvalidTreeNodeValue,4,4});
        std::cout << s.isBalanced(root) << std::endl;
    }
}