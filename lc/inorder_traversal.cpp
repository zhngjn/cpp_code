#include <vector>
#include <stack>
#include <iostream>
#include <unordered_set>

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
    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        if (!root)
            return {};

        std::vector<int> inorder;
        std::stack<TreeNode*> nodes;
        std::unordered_set<TreeNode*> left_visited;

        const auto is_left_visited = [&left_visited](TreeNode* node){
            return left_visited.find(node) != left_visited.end();
        };
        const auto mark_left_visited = [&left_visited](TreeNode* node){
            return left_visited.insert(node);
        };

        nodes.push(root);
        while (!nodes.empty())
        {
            TreeNode* cur = nodes.top();
            nodes.pop();
            
            if (cur->left && !is_left_visited(cur))
            {
                nodes.push(cur);
                nodes.push(cur->left);
                mark_left_visited(cur);
            }
            else
            {
                inorder.emplace_back(cur->val);
                if (cur->right)
                    nodes.push(cur->right);
            }
        }

        return inorder;
    }
};

int main()
{
    Solution s;

    {
        TreeNode n1(1), n2(2), n3(3);
        n1.right = &n2;
        n2.left = &n3;

        const auto pre = s.inorderTraversal(&n1);

        for (const auto v : pre)
        {
            std::cout << v << ",";
        }
        std::cout << std::endl;
    }
}