#include <iostream>
#include <limits>
#include <queue>

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
    bool isSymmetric(TreeNode* root) 
    {
        if (!root)
            return true;

        std::queue<TreeNode*> left_Q, right_Q;
        left_Q.push(root);
        right_Q.push(root);
        while (!left_Q.empty())
        {
            TreeNode* left_cur = left_Q.front();
            left_Q.pop();
            TreeNode* right_cur = right_Q.front();
            right_Q.pop();

            if (!left_cur && !right_cur)
                continue;
            else if (!left_cur || !right_cur)
                return false;
            else if (left_cur->val != right_cur->val)
                return false;

            left_Q.push(left_cur->left);
            left_Q.push(left_cur->right);
            right_Q.push(right_cur->right);
            right_Q.push(right_cur->left);
        }
        return true;
    }
};

int main()
{
    Solution s;

    {
        TreeNode n4(3), n5(4), n6(4), n7(3), n2(2, &n4, &n5), n3(2, &n6, &n7), n1(1, &n2, &n3);
        std::cout << s.isSymmetric(&n1) << std::endl;
    }
    {
        TreeNode n4(3), n5(3), n2(2, nullptr, &n4), n3(2, nullptr, &n5), n1(1, &n2, &n3);
        std::cout << s.isSymmetric(&n1) << std::endl;
    }
}