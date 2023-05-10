#include <string>
#include <iostream>
#include <stack>
#include <algorithm>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};
 
class Solution 
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        std::string rep_p, rep_q;
        bool res = findNodes(root, p, q, rep_p, rep_q);
        if (!res)
            return nullptr;

        std::size_t min_size = std::min(rep_p.size(), rep_q.size());
        std::size_t lowest = 0;
        while (lowest < min_size && rep_p[lowest] == rep_q[lowest])
            lowest++;

        std::string rep_lowest = rep_p.substr(0, lowest);

        return findNodeByRep(root, rep_lowest);
    }

private:
    struct TreeNodeWithInfo
    {
        TreeNode* node;
        std::string rep;
    };

    bool findNodes(TreeNode* root, TreeNode* p, TreeNode* q, std::string& rep_p, std::string& rep_q)
    {
        if (!root)
            return false;
        
        std::size_t counter = 0;
        std::stack<TreeNodeWithInfo> nodes;
        nodes.push({root, "0"});
        while (!nodes.empty())
        {
            TreeNodeWithInfo cur = nodes.top();
            nodes.pop();

            if (cur.node == p)
            {
                rep_p = cur.rep;
                counter++;
                if (counter >= 2)
                    return true;
            }
            if (cur.node == q)
            {
                rep_q = cur.rep;
                counter++;
                if (counter >= 2)
                    return true;
            }

            if (cur.node->right)
                nodes.push({cur.node->right, cur.rep + '1'});
            if (cur.node->left)
                nodes.push({cur.node->left, cur.rep + '0'});
        }
        return false;
    }

    TreeNode* findNodeByRep(TreeNode* root, const std::string& rep)
    {
        if (!root)
            return nullptr;
        if (rep.size() == 1)
            return root;

        TreeNode* node = root;
        for (std::size_t i = 1; i < rep.size(); i++)
        {
            if (rep[i] == '0')
                node = node->left;
            else
                node = node->right;
        }

        return node;
    }
};

int main()
{
    Solution s;

    TreeNode n7(7), n4(4);
    TreeNode n2(2, &n7, &n4);
    TreeNode n6(6);
    TreeNode n5(5, &n6, &n2);
    TreeNode n0(0), n8(8);
    TreeNode n1(1, &n0, &n8);
    TreeNode n3(3, &n5, &n1);

    std::cout << s.lowestCommonAncestor(&n3, &n5, &n1)->val << std::endl;
    std::cout << s.lowestCommonAncestor(&n3, &n5, &n4)->val << std::endl;
}