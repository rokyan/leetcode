// https://leetcode.com/problems/add-two-numbers/description/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto carry = 0;

        ListNode* head = nullptr;
        ListNode* node = nullptr;
        
        for (auto pt1 = l1, pt2 = l2; pt1 != nullptr || pt2 != nullptr || carry > 0; )
        {
            auto x = 0;
            
            if (pt1 != nullptr)
            {
                x = pt1->val;
                pt1 = pt1->next;
            }
            
            auto y = 0;
            
            if (pt2 != nullptr)
            {
                y = pt2->val;
                pt2 = pt2->next;
            }
            
            auto res = x + y + carry;
            carry = res / 10;
            res = res % 10;
            
            if (node == nullptr)
            {
                node = new ListNode { res };
                head = node;
            }
            else
            {
                node->next = new ListNode { res };
                node = node->next;
            }
        }
        
        return head;
    }
};