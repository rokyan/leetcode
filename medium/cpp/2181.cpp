// https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head)
    {
        auto node = head;
        ListNode* prev = nullptr;
        
        while (node->next != nullptr)
        {
            while (node->next->val != 0)
            {
                node->val += node->next->val;
                node->next = node->next->next;
            }
            
            prev = node;
            node = node->next;
        }
        
        prev->next = nullptr;
        
        return head;
    }
};