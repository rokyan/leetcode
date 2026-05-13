// https://leetcode.com/problems/reverse-nodes-in-k-group/description/

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
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        ListNode* first = head;
        ListNode* prev = nullptr;
        ListNode* updHead = nullptr;

        while (first != nullptr)
        {
            ListNode* last = first;
            int times = k;

            while (--times && last->next != nullptr)
            {
                last = last->next;
            }

            if (times > 0)
            {
                break;
            }

            ListNode* next = last->next;

            ListNode* tail = nullptr;
            ListNode* revHead = first;

            while (first != next)
            {
                ListNode* temp = first->next;
                first->next = tail;
                tail = first;
                first = temp;
            }

            if (prev != nullptr)
            {
                prev->next = tail;
            }

            revHead->next = next;
            prev = revHead;

            first = next;

            if (updHead == nullptr)
            {
                updHead = tail;
            }
        }

        return updHead == nullptr ? head : updHead;
    }
};