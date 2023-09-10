// https://leetcode.com/problems/linked-list-cycle-ii/description/

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
    ListNode* detectCycle(ListNode* head)
    {
        auto slow = head;
        auto fast = head;
        
        for (;;)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return nullptr;
            }

            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
            {
                auto node = head;
                
                while (slow != node)
                {
                    slow = slow->next;
                    node = node->next;
                }
                
                return node;
            }
        }
        
        return nullptr;
    }
};