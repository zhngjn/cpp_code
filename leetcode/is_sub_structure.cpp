#include <iostream>

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
    bool isSubStructure(TreeNode* A, TreeNode* B) 
    {
        if (!B)
            return false;

        return isSubStructureImpl(A, B);
    }

private:
    bool isSubStructureImpl(TreeNode* a, TreeNode* b) 
    {
        if (!a)
            return false;

        if (isSubStructureAt(a, b))
            return true;

        return isSubStructureImpl(a->left, b) || isSubStructureImpl(a->right, b);
    }

    bool isSubStructureAt(TreeNode* a, TreeNode* b)
    {
        if (a->val != b->val)
            return false;

        bool left_matched = !b->left || (a->left && isSubStructureAt(a->left, b->left));
        if (!left_matched)
            return false;
        bool right_matched = !b->right || (a->right && isSubStructureAt(a->right, b->right));
        if (!right_matched)
            return false;

        return true;
    }
};

int main()
{
    Solution s;

    {
        TreeNode n1(1), n2(2), n4(4, &n1, &n2);
        TreeNode n5(5);
        TreeNode n3(3, &n4, &n5);

        TreeNode nn1(1), nn4(4, &n1, nullptr);
        std::cout << s.isSubStructure(&n3, &nn4) << std::endl;
    }
    {
        TreeNode n1(1), n2(2), n4(4, &n1, &n2);
        TreeNode n5(5);
        TreeNode n3(3, &n4, &n5);

        TreeNode nn1(1), nn3(3, &n1, nullptr);
        std::cout << s.isSubStructure(&n3, &nn3) << std::endl;
    }
}