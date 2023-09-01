// https://leetcode.com/problems/reverse-nodes-in-even-length-groups/description/

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
    ListNode* reverseEvenLengthGroups(ListNode* head)
    {
        auto fake = new ListNode(0, head);
        auto node = head;
        auto prev = fake;

        for (auto group_size = 1; node != nullptr; group_size++)
        {
            auto last = node;

            auto times = group_size;
            auto cnt = 0;
            while (last != nullptr && times--)
            {
                cnt++;
                last = last->next;
            }

            if (cnt % 2 == 0)
            {
                auto head = rev(node, last);
                prev->next = head;
            }

            node = last;

            times = group_size;
            while (prev != nullptr && times--)
            {
                prev = prev->next;
            }
        }

        return fake->next;
    }

private:
    ListNode* rev(ListNode* first, ListNode* last)
    {
        auto head = last;

        while (first != last)
        {
            auto next = first->next;
            first->next = head;
            head = first;
            first = next;
        }

        return head;
    }
};