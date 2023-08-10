// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/

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
    ListNode* insertGreatestCommonDivisors(ListNode* head)
    {
        auto node = head;

        while (node->next != nullptr)
        {
            const auto val = gcd(node->val, node->next->val);
            auto next = node->next;
            node->next = new ListNode(val, next);
            node = next;
        }

        return head;
    }

private:
    int gcd(int x, int y)
    {
        if (x == 0)
        {
            return y;
        }

        return gcd(y % x, x);
    }
};