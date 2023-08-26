// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution
{
public:
    ListNode* removeZeroSumSublists(ListNode* head)
    {
        std::unordered_map<int, ListNode*> m;

        auto f_head = new ListNode(0, head);
        m[0] = f_head;

        auto s = 0;

        while (head != nullptr)
        {
            s += head->val;

            if (const auto it = m.find(s); it != std::end(m))
            {
                auto node = it->second->next;
                auto ns = s;

                while (node != head)
                {
                    ns += node->val;
                    m.erase(ns);
                    node = node->next;
                }

                it->second->next = head->next;
                head = head->next;
            }
            else
            {
                m[s] = head;
                head = head->next;
            }
        }

        return f_head->next;
    }
};