#include <vector>
#include <iostream>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
// class Solution 
// {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) 
//     {
//         if (!head || !head->next || k < 2)
//             return head;

//         bool last_need_reverse;
//         std::vector<ListNode*> heads = getGroups(head, k, last_need_reverse);

//         std::vector<std::pair<ListNode*, ListNode*>> reversed_groups;
//         for (std::size_t i = 0; i < heads.size(); i++)
//         {
//             if (i != heads.size() - 1 || last_need_reverse)
//                 reversed_groups.emplace_back(reverseGroup(heads[i], true));
//             else
//                 reversed_groups.emplace_back(reverseGroup(heads[i], false));
//         }

//         for (std::size_t i = 0; i < reversed_groups.size() - 1; i++)
//             reversed_groups[i].second->next = reversed_groups[i + 1].first;

//         return reversed_groups[0].first;
//     }

// private:
//     std::vector<ListNode*> getGroups(ListNode* head, int k, bool& last_need_reverse)
//     {
//         std::vector<ListNode*> heads;
//         ListNode* prev = nullptr;
//         while (head)
//         {
//             heads.emplace_back(head);
//             if (prev)
//                 prev->next = nullptr;

//             int i = 1;
//             while (head && i <= k)
//             {
//                 prev = head;
//                 head = head->next;
//                 i++;
//             }
//             if (i <= k) 
//                 last_need_reverse = false;
//             else
//                 last_need_reverse = true;
//         }
//         return heads;
//     }

//     std::pair<ListNode*, ListNode*>
//     reverseGroup(ListNode* head, bool reverse) 
//     {
//         if (!reverse)
//         {
//             ListNode* p = head;
//             while (p->next)
//                 p = p->next;
//             return std::make_pair(head, p);
//         }

//         ListNode* p = nullptr, *q = head, *r = q->next;
//         while (r)
//         {
//             q->next = p;
//             p = q;
//             q = r;
//             r = r->next;
//         }
//         q->next = p;
//         return std::make_pair(q, head);
//     }
// };

class Solution 
{
public:
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if (!head || !head->next || k < 2)
            return head;

        bool first = true;
        bool need_reverse;
        ListNode* next_node = head;
        std::pair<ListNode*, ListNode*> first_group, prev_group;
        std::pair<ListNode*, ListNode*> next_group = getNextGroup(next_node, k, need_reverse, &next_node);
        while (next_group.first)
        {
            if (first)
            {
                const auto reversed_group = reverseGroupOrNot(next_group.first, need_reverse);
                first_group = prev_group = reversed_group;
                first = false;
            }
            else
            {
                const auto reversed_group = reverseGroupOrNot(next_group.first, need_reverse);
                prev_group.second->next = reversed_group.first;
                prev_group = reversed_group;
            }

            next_group = getNextGroup(next_node, k, need_reverse, &next_node);
        }
 
        return first_group.first;
    }

private:
    std::pair<ListNode*, ListNode*> 
    getNextGroup(ListNode* head, int k, bool& need_reverse, ListNode** next_node)
    {
        ListNode* cur = head, *prev = nullptr;
        int i = 1;
        while (cur && i <= k)
        {
            prev = cur;
            cur = cur->next;
            i++;
        }
        if (prev)
            prev->next = nullptr;

        if (i <= k)
            need_reverse = false;
        else
            need_reverse = true;
        
        *next_node = cur;

        return std::make_pair(head, prev);
    }

    std::pair<ListNode*, ListNode*>
    reverseGroupOrNot(ListNode* head, bool need_reverse) 
    {
        if (!need_reverse)
        {
            ListNode* p = head;
            while (p->next)
                p = p->next;
            return std::make_pair(head, p);
        }

        ListNode* p = nullptr, *q = head, *r = q->next;
        while (r)
        {
            q->next = p;
            p = q;
            q = r;
            r = r->next;
        }
        q->next = p;
        return std::make_pair(q, head);
    }
};

int main()
{
    const auto print_list = [](ListNode* head){
        while (head) {
            std::cout << head->val << " -> ";
            head = head->next;
        }
        std::cout << std::endl;
    };

    Solution s;

    {
        ListNode n5(5), n4(4, &n5), n3(3, &n4), n2(2, &n3), n1(1, &n2);
        ListNode* p = s.reverseKGroup(&n1, 2);
        print_list(p);
    }
    {
        ListNode n5(5), n4(4, &n5), n3(3, &n4), n2(2, &n3), n1(1, &n2);
        ListNode* p = s.reverseKGroup(&n1, 3);
        print_list(p);
    }
}