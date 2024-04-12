// https://leetcode.com/problems/sort-linked-list-already-sorted-using-absolute-values/description/

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
    ListNode* sortLinkedList(ListNode* head)
    {
        auto neg = new ListNode;
        auto non_neg = new ListNode;
        auto last_neg = neg;
        auto last_non_neg = non_neg;

        for (auto node = head; node != nullptr; node = node->next)
        {
            if (node->val < 0)
            {
                last_neg->next = node;
                last_neg = last_neg->next;
            }
            else
            {
                last_non_neg->next = node;
                last_non_neg = last_non_neg->next;
            }
        }

        last_neg->next = last_non_neg->next = nullptr;

        if (neg->next == nullptr)
        {
            return non_neg->next;
        }

        auto rev_neg = static_cast<ListNode*>(nullptr);

        for (auto node = neg->next; node != nullptr; )
        {
            auto next = node->next;
            node->next = rev_neg;
            rev_neg = node;
            node = next;
        }

        auto node = rev_neg;

        while (node->next != nullptr)
        {
            node = node->next;
        }

        node->next = non_neg->next;

        return rev_neg;
    }
};