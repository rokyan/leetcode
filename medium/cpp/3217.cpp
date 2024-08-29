// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/

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
    ListNode* modifiedList(std::vector<int>& nums, ListNode* head)
    {
        std::unordered_set<int> un(std::cbegin(nums), std::cend(nums));

        auto fake = new ListNode(-1, head);
        auto prev = fake;

        while (head != nullptr)
        {
            if (const auto it = un.find(head->val); it != std::end(un))
            {
                prev->next = head->next;
            }
            else
            {
                prev = head;
            }

            head = head->next;
        }

        return fake->next;
    }
};