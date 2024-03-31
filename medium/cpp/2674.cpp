// https://leetcode.com/problems/split-a-circular-linked-list/description/

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
    std::vector<ListNode*> splitCircularLinkedList(ListNode* list)
    {
        auto end = list;
        auto len = 1;

        while (end->next != list)
        {
            len++;
            end = end->next;
        }

        auto times = (len - 1) / 2;
        auto mid = list;

        while (times--)
        {
            mid = mid->next;
        }

        end->next = mid->next;
        auto list2 = mid->next;
        mid->next = list;

        return { list, list2 };
    }
};