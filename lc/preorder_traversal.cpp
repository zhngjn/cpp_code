#include <stack>
#include <vector>
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
    std::vector<int> preorderTraversal(TreeNode* root) 
    {
        if (!root)
            return {};
        
        std::vector<int> preorder;
        std::stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            TreeNode* cur = nodes.top();
            nodes.pop();

            preorder.emplace_back(cur->val);

            if (cur->right)
                nodes.push(cur->right);
            if (cur->left)
                nodes.push(cur->left);
        }

        return preorder;
    }
};

int main()
{
    Solution s;

    {
        TreeNode n1(1), n2(2), n3(3);
        n1.right = &n2;
        n2.left = &n3;

        const auto pre = s.preorderTraversal(&n1);

        for (const auto v : pre)
        {
            std::cout << v << ",";
        }
        std::cout << std::endl;
    }
}