// https://leetcode.com/problems/remove-nodes-from-linked-list/description/

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
    ListNode* removeNodes(ListNode* head)
    {
        return solve(head);
    }

private:
    ListNode* solve(ListNode* node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        const auto next = solve(node->next);

        node->next = next;

        return (next == nullptr || node->val >= next->val) ? node : next;
    }
};