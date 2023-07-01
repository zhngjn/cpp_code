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

        int height = calcHight(root);

        return countNodesImpl(root, height);
    }

private:
    int countNodesImpl(TreeNode* root, int height)
    {
        if (!root || height < 0)
            return 0;
        else if (height == 0)
            return 1;

        if (leftFull(root, height))
        {
            return 1 + calcFullSize(height - 1) + countNodesImpl(root->right, height - 1);
        }
        else
        {
            return 1 + countNodesImpl(root->left, height - 1) + calcFullSize(height - 2);
        }
    }

    // pre-condition: height >= 0
    int calcHight(TreeNode* root)
    {
        int height = 0;
        while (root->left)
        {
            height++;
            root = root->left;
        }
        return height;
    }

    // pre-condition: height >= 1
    bool leftFull(TreeNode* root, int height)
    {
        int h = 0;
        root = root->left;
        while (h < height - 1 && root)
        {
            root = root->right;
            h++;
        }
        return root != nullptr;
    }

    int calcFullSize(int height)
    {
        if (height < 0)
            return 0;

        return (1 << (height + 1)) - 1;
    }
};

int main()
{
    Solution s;

    {
        TreeNode n4(4), n5(5), n2(2, &n4, &n5), n6(6), n3(3, &n6, nullptr), n1(1, &n2, &n3);
        std::cout << s.countNodes(&n1) << std::endl;
    }
    {
        TreeNode n4(4), n2(2, &n4, nullptr), n3(3), n1(1, &n2, &n3);
        std::cout << s.countNodes(&n1) << std::endl;
    }
}