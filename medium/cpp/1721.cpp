// https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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
    ListNode* swapNodes(ListNode* head, int k)
    {       
        auto node = head;
        
        while (--k)
        {
            node = node->next;
        }
        
        auto first = node;        
        auto second = head;
        
        while (node->next != nullptr)
        {
            second = second->next;
            node = node->next;
        }
        
        std::swap(first->val, second->val);
        
        return head;
    }
};