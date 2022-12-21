// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (head == nullptr)
        {
            return head;
        }
        
        ListNode* first = head;
        ListNode* last = head;
        ListNode* prev = nullptr;
        
        while (n--)
        {
            last = last->next;
        }
        
        while (last != nullptr)
        {
            prev = first;
            first = first->next;            
            last = last->next;
        }

        if (prev != nullptr)
        {
            prev->next = first->next;
        }
        else
        {
            head = head->next;
        }
        
        return head;
    }
};