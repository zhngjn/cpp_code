#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) 
    {
        std::queue<TreeNode*> left_Q, right_Q;
        left_Q.push(p);
        right_Q.push(q);
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
            right_Q.push(right_cur->left);
            right_Q.push(right_cur->right);
        }
        return true;
    }

    // bool isSameTree(TreeNode* p, TreeNode* q) 
    // {
    //     return (p && q && p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) || (!p && !q);
    // }
};

int main()
{
    Solution s;

    {
        TreeNode n2(2), n3(3), n1(1, &n2, &n3);
        TreeNode n2_2(2), n3_2(3), n1_2(1, &n2_2, &n3_2);
        std::cout << s.isSameTree(&n1, &n1_2) << std::endl;
    }
    {
        TreeNode n2(2), n1(1, &n2, nullptr);
        TreeNode n2_2(2), n1_2(1, nullptr, &n2_2);
        std::cout << s.isSameTree(&n1, &n1_2) << std::endl;
    }
}