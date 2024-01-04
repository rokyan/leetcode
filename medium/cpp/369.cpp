// https://leetcode.com/problems/plus-one-linked-list/description/

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
    ListNode* plusOne(ListNode* head)
    {
        const auto carry = add(head);

        if (carry > 0)
        {
            const auto n_head = new ListNode(carry, head);
            head = n_head;
        }

        return head;
    }

private:
    int add(ListNode* node)
    {
        if (node->next == nullptr)
        {
            node->val++;
            const auto carry = node->val / 10;
            node->val %= 10;
            return carry; 
        }
        else
        {
            auto carry = add(node->next);
            node->val += carry;
            carry = node->val / 10;
            node->val %= 10;
            return carry;
        }
    }
};