#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* n) : val(x), next(n) {}
};
 
class Solution 
{
public:
    ListNode* getKthFromEnd(ListNode* head, int k) 
    {
        if (!head || k < 1)
            return nullptr;

        int i = -k;
        ListNode* target = head;
        while (head->next)
        {
            head = head->next;
            i++;
            if (i >= 0)
                target = target->next;
        }

        return i >= -1 ? target : nullptr;
    }
};

int main()
{
    Solution s;

    {
        ListNode n5(5), n4(4, &n5), n3(3, &n4), n2(2, &n3), n1(1, &n2);
        std::cout << s.getKthFromEnd(&n1, 2)->val << std::endl;
    }
}