// https://leetcode.com/problems/odd-even-linked-list/description/

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
    ListNode* oddEvenList(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        auto odd_head = head->next;

        auto even_node = head;
        auto odd_node = head->next;

        while (even_node->next != nullptr && odd_node->next != nullptr)
        {
            even_node->next = even_node->next->next;
            even_node = even_node->next;

            odd_node->next = odd_node->next->next;
            odd_node = odd_node->next;
        }

        even_node->next = odd_head;

        return head;
    }
};