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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto fake = new ListNode{42};
        auto prev = fake;
        auto carry = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            const auto sum = carry
                + (l1 != nullptr ? l1->val : 0)
                + (l2 != nullptr ? l2->val : 0);
            const auto node = new ListNode{sum % 10};
            carry = sum / 10;

            prev->next = node;
            prev = node;

            if (l1 != nullptr)
            {
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                l2 = l2->next;
            }
        }

        if (carry)
        {
            prev->next = new ListNode{carry};
        }

        return fake->next;
    }
};