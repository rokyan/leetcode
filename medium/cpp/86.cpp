// https://leetcode.com/problems/partition-list/description/

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
    ListNode* partition(ListNode* head, int x)
    {
        auto fakeHeadFirst = new ListNode();
        auto first = fakeHeadFirst;

        auto fakeHeadSecond = new ListNode();
        auto second = fakeHeadSecond;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                first->next = head;
                first = first->next;
            }
            else
            {
                second->next = head;
                second = second->next;
            }

            head = head->next;
        }

        first->next = fakeHeadSecond->next;
        second->next = nullptr;

        return fakeHeadFirst->next;
    }
};