#include <stack>
#include <vector>
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
    std::vector<int> postorderTraversal(TreeNode* root) 
    {
        if (!root)
            return {};
        
        std::vector<int> postorder;
        std::stack<TreeNode*> nodes;
        std::unordered_set<TreeNode*> children_visited;

        const auto is_children_visited = [&children_visited](TreeNode* node){
            return children_visited.find(node) != children_visited.end();
        };
        const auto mark_children_visited = [&children_visited](TreeNode* node){
            return children_visited.insert(node);
        };

        nodes.push(root);
        while (!nodes.empty())
        {
            TreeNode* cur = nodes.top();
            nodes.pop();

            if (cur->left || cur->right)
            {
                if (!is_children_visited(cur))
                {
                    nodes.push(cur);
                    if (cur->right)
                        nodes.push(cur->right);
                    if (cur->left)
                        nodes.push(cur->left);

                    mark_children_visited(cur);
                }
                else
                {
                    postorder.emplace_back(cur->val);
                }
            }
            else
            {
                postorder.emplace_back(cur->val);
            }
        }
        
        return postorder;
    }
};

int main()
{
    Solution s;

    {
        TreeNode n1(1), n2(2), n3(3);
        n1.right = &n2;
        n2.left = &n3;

        const auto pre = s.postorderTraversal(&n1);

        for (const auto v : pre)
        {
            std::cout << v << ",";
        }
        std::cout << std::endl;
    }
}