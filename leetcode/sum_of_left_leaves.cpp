#include <iostream>
#include <stack>

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
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if (!root)
            return 0;

        int sum = 0;
        State state{Right};
        std::stack<TreeNode*> ST;
        ST.push(root);
        while (!ST.empty())
        {
            TreeNode* cur = ST.top();
            ST.pop();

            // leaf node
            if (!cur->left && !cur->right)
            {
                if (state.last_leaf_dir == Left)
                {
                    sum += cur->val;
                    state.last_leaf_dir = Right;
                }
            }
            else
            {
                if (cur->right)
                {
                    ST.push(cur->right);
                    state.last_leaf_dir = Right;
                }
                if (cur->left)
                {
                    ST.push(cur->left);
                    state.last_leaf_dir = Left;
                }
            }
        }

        return sum;
    }

private:
    enum Dir
    {
        Left, Right
    };

    struct State
    {
        Dir last_leaf_dir;
    };
};

int main()
{
    Solution s;

    {
        TreeNode n15(15), n7(7), n20(20, &n15, &n7), n9(9), n3(3, &n9, &n20);
        std::cout << s.sumOfLeftLeaves(&n3) << std::endl;
    }
    {
        TreeNode n4(4), n5(5), n2(2, &n4, &n5), n3(3), n1(1, &n2, &n3);
        std::cout << s.sumOfLeftLeaves(&n1) << std::endl;
    }
}