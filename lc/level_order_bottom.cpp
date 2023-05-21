#include <iostream>
#include <vector>
#include <stack>
#include <queue>

#include "util/to_string.hpp"

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
    std::vector<std::vector<int>> levelOrderBottom(TreeNode* root) 
    {
        if (!root)
            return {};

        std::queue<NodeInfo> Q;
        std::stack<NodeInfo> ST;
        Q.push(NodeInfo{root, 0});
        while (!Q.empty())
        {
            NodeInfo cur = Q.front();
            Q.pop();

            ST.push(cur);

            if (cur.node->right)
                Q.push(NodeInfo{cur.node->right, cur.level + 1});
            if (cur.node->left)
                Q.push(NodeInfo{cur.node->left, cur.level + 1});
        }

        std::vector<std::vector<int>> levels_values;
        std::vector<int> level_values;
        int cur_level = ST.top().level;
        while (!ST.empty())
        {
            NodeInfo cur = ST.top();
            ST.pop();

            if (cur.level == cur_level)
                level_values.emplace_back(cur.node->val);
            else
            {
                levels_values.emplace_back(std::move(level_values));
                level_values = std::vector<int>{};
                level_values.emplace_back(cur.node->val);
                cur_level = cur.level;
            }
        }
        levels_values.emplace_back(std::move(level_values));

        return levels_values;
    }

private:
    struct NodeInfo
    {
        TreeNode* node;
        int level;
    };
};

int main()
{
    Solution s;

    {
        TreeNode n15(15), n7(7), n20(20, &n15, &n7), n9(9), n3(3, &n9, &n20);
        const auto levels_values = s.levelOrderBottom(&n3);
        std::cout << util::toString(levels_values) << std::endl;
    }
}