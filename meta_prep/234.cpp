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
    bool isPalindrome(ListNode* head)
    {
        auto len = 0;
        auto node = head;

        while (node != nullptr)
        {
            len++;
            node = node->next;
        }

        auto mid = len / 2;
        auto mid_node = head;

        for (auto i = 0; i < mid; i++)
        {
            mid_node = mid_node->next;
        }

        ListNode* rev_head = nullptr;
        node = mid_node;

        while (node != nullptr)
        {
            auto next = node->next;
            node->next = rev_head;
            rev_head = node;
            node = next;
        }

        for (auto i = 0; i < mid; i++)
        {
            if (head->val != rev_head->val)
            {
                return false;
            }

            head = head->next;
            rev_head = rev_head->next;
        }

        return true;
    }
};