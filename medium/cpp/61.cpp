// https://leetcode.com/problems/rotate-list/

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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == nullptr)
        {
            return head;
        }
        
        int length = get_length(head);
        
        k = k % length;
        
        if (k == 0)
        {
            return head;
        }
        
        int n = length - k;
        auto n_head = head;
        
        while (n--)
        {
            n_head = n_head->next;
        }
        
        auto tail = n_head;
        
        while (tail->next)
        {
            tail = tail->next;
        }
        
        tail->next = head;
        
        while (head->next != n_head)
        {
            head = head->next;
        }
        
        head->next = nullptr;
        
        return n_head;
    }
    
private:
    int get_length(ListNode* node)
    {
        int length = 0;
        
        while (node != nullptr)
        {
            length++;
            node = node->next;
        }
        
        return length;
    }
};