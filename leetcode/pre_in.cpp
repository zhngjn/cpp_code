#include <vector>
#include <algorithm>
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) 
    {
        return buildTreeRecursively(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

private:
    TreeNode* buildTreeRecursively(
        std::vector<int>& preorder, int pre_left, int pre_right,
        std::vector<int>& inorder, int in_left, int in_right)
    {
        if (pre_left >= pre_right)
            return nullptr;

        if (pre_right - pre_left == 1)
            return new TreeNode(preorder[pre_left]);

        int cur_value = preorder[pre_left];
        int in_middle = std::distance(inorder.begin(), std::find(inorder.begin(), inorder.end(), cur_value));
        int pre_middle = pre_left + (in_middle - in_left);
        TreeNode* left_child = buildTreeRecursively(preorder, pre_left + 1, pre_middle + 1, inorder, in_left, in_middle);
        TreeNode* right_child = buildTreeRecursively(preorder, pre_middle + 1, pre_right, inorder, in_middle + 1, in_right);
        return new TreeNode(cur_value, left_child, right_child);
    } 
};

void visitTree(TreeNode* root)
{
    if (!root)
        return;

    std::cout << root->val << ",";
    visitTree(root->left);
    visitTree(root->right);
}

int main()
{
    Solution s;

    std::vector<int> pre = {3,9,20,15,7}, in = {9,3,15,20,7};
    TreeNode* root = s.buildTree(pre, in);
    visitTree(root);
    std::cout << std::endl;
}