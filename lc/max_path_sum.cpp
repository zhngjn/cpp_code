#include <algorithm>
#include <iostream>
#include <limits>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution 
{
public:
    int maxPathSum(TreeNode* root) 
    {
        PathSum path_sum = maxPathSumImpl(root);
        return std::max(path_sum.max_sum, path_sum.max_sum_to_root);
    }

private:
    struct PathSum
    {
        int max_sum, max_sum_to_root;
    };

    PathSum maxPathSumImpl(TreeNode* root) 
    {
        if (!root)
            return {-1000000, -1000000};

        PathSum left = maxPathSumImpl(root->left);
        PathSum right = maxPathSumImpl(root->right);

        int max_sum = std::max(left.max_sum, right.max_sum);
        int max_sum_via_root = root->val;
        max_sum_via_root += std::max(left.max_sum_to_root, 0);
        max_sum_via_root += std::max(right.max_sum_to_root, 0);
        max_sum = std::max(max_sum, max_sum_via_root);

        int max_sum_to_root = std::max(
            std::max(root->val, root->val + left.max_sum_to_root),
            root->val + right.max_sum_to_root);

        return {max_sum, max_sum_to_root};
    }
};

int main()
{
    Solution s;

    {
        TreeNode n2(2), n3(3), n1(1, &n2, &n3);
        std::cout << s.maxPathSum(&n1) << std::endl;
    }
    {
        TreeNode n15(15), n7(7), n20(20, &n15, &n7), n9(9), n_10(-10, &n9, &n20);
        std::cout << s.maxPathSum(&n_10) << std::endl;
    }
    {
        TreeNode n_3(-3);
        std::cout << s.maxPathSum(&n_3) << std::endl;
    }
}