// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

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
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode* fake_head = new ListNode(-111, head);
        
        auto node = fake_head;
        ListNode* prev = nullptr;
        
        while (node != nullptr)
        {
            bool is_dupe = false;
            
            while (node->next != nullptr && node->val == node->next->val)
            {
                is_dupe = true;
                node->next = node->next->next;
            }
            
            if (is_dupe)
            {
                prev->next = node->next;
            }
            else
            {
                prev = node;
            }
            
            node = node->next;
        }
        
        return fake_head->next;
    }
};