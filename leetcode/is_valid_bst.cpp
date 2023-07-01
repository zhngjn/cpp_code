#include <iostream>
#include <limits>
#include <cstdint>

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
    bool isValidBST(TreeNode* root) 
    {
        std::int64_t cur_value = std::numeric_limits<std::int64_t>::min();
        
        return inorder(root, cur_value);
    }

private:
    bool inorder(TreeNode* root, std::int64_t& cur_value)
    {
        if (!root)
            return true;

        if (!inorder(root->left, cur_value))
            return false;

        if (root->val <= cur_value)
            return false;
        else
            cur_value = root->val;

        return inorder(root->right, cur_value);
    }
};

int main()
{
    Solution s;

    {
        TreeNode n1(1), n3(3), n2(2, &n1, &n3);
        std::cout << s.isValidBST(&n2) << std::endl;
    }
    {
        TreeNode n3(3), n6(6), n4(4, &n3, &n6), n1(1), n5(5, &n1, &n4);
        std::cout << s.isValidBST(&n5) << std::endl;
    }
}