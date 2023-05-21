#include <iostream>
#include <queue>

#include "util/bin_tree.hpp"

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
    TreeNode* invertTree(TreeNode* root) 
    {
        std::queue<TreeNode*> Q;
        Q.push(root);
        while (!Q.empty())
        {
            TreeNode* cur = Q.front();
            Q.pop();

            if (!cur || (!cur->left && !cur->right))
                continue;

            TreeNode* left = cur->left;
            TreeNode* right = cur->right;
            // swap
            cur->left = right;
            cur->right = left;

            Q.push(right);
            Q.push(left);
        }

        return root;
    }
};

int main()
{
    Solution s;

    {
        TreeNode n1(1), n3(3), n2(2, &n1, &n3), n6(6), n9(9), n7(7, &n6, &n9), n4(4, &n2, &n7);
        TreeNode* inverted = s.invertTree(&n4);
        util::printTree_preOrder(inverted);
    }
}