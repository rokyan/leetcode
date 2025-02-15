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
    ListNode* mergeKLists(std::vector<ListNode*>& lists)
    {
        const auto n = std::size(lists);

        auto head = new ListNode();
        auto cur = head;

        auto comp = [](ListNode* left, ListNode* right)
        {
            return left->val > right->val;
        };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> pq;

        for (auto i = 0; i < n; i++)
        {
            if (lists[i] != nullptr)
            {
                pq.push(lists[i]);
            }
        }

        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();

            cur->next = node;
            cur = cur->next;

            if (node->next != nullptr)
            {
                pq.push(node->next);
            }
        }

        return head->next;
    }
};