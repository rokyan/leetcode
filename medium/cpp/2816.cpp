// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/

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
    ListNode* doubleIt(ListNode* head)
    {
        const auto value = mult(head);

        if (value > 0)
        {
            head = new ListNode(value, head);
        }

        return head;
    }

private:
    int mult(ListNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        const auto carry = mult(node->next);

        const auto value = 2 * node->val + carry;

        node->val = value % 10;
        return value / 10;
    }
};