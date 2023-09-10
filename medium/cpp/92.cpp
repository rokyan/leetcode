// https://leetcode.com/problems/reverse-linked-list-ii/description/

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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        auto fake_head = new ListNode(0, head);

        auto first = fake_head;
        auto prev_first = static_cast<ListNode*>(nullptr);

        while (left--)
        {
            prev_first = first;
            first = first->next;
        }

        auto last = fake_head;

        while (right--)
        {
            last = last->next;
        }

        auto next_last = last->next;

        auto node = first;
        auto rev_head = static_cast<ListNode*>(nullptr);
        auto rev_tail = static_cast<ListNode*>(nullptr);;

        while (node != next_last)
        {
            auto next = node->next;
            node->next = rev_head;
            rev_head = node;

            if (rev_tail == nullptr)
            {
                rev_tail = rev_head;
            }

            node = next;
        }

        prev_first->next = rev_head;
        rev_tail->next = next_last;

        return fake_head->next;
    }
};