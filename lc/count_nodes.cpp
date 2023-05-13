#include <iostream>

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
    int countNodes(TreeNode* root) 
    {
        if (!root)
            return 0;
        else if (!root->left && !root->right)

        TreeNode* left_sibling = nullptr;
        TreeNode* right_most = root;
        while (right_most)
        {
            
        }
    }
};

int main()
{

}