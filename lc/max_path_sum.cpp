
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
        return maxPathOfNode()
    }

private:
    int maxPathOfNode(TreeNode* root)
    {
        if (!root)
            return 0;
        
        return maxElement(
            maxPathOfNode(root->left) + root->val,
            maxPathOfNode(root->right) + root->val,
            0);
    }

    int maxElement(int a, int b, int c)
    {

    }
};