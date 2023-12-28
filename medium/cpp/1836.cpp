// https://leetcode.com/problems/remove-duplicates-from-an-unsorted-linked-list/description/

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
    ListNode* deleteDuplicatesUnsorted(ListNode* head)
    {
        std::unordered_map<int, int> cnt;

        auto node = head;
        while (node != nullptr)
        {
            cnt[node->val]++;
            node = node->next;
        }

        auto fake = new ListNode(-1, head);
        node = fake;

        while (node->next != nullptr)
        {
            if (cnt[node->next->val] == 1)
            {
                node = node->next;
            }
            else
            {
                node->next = node->next->next;
            }
        }

        return fake->next;
    }
};