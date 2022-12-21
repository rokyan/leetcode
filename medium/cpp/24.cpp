// https://leetcode.com/problems/swap-nodes-in-pairs/description/

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
    ListNode* swapPairs(ListNode* head)
    {
        auto node = head;

        while (node != nullptr && node->next != nullptr)
        {
            std::swap(node->val, node->next->val);
            node = node->next->next;
        }

        return head;
    }
};