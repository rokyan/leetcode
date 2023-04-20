// https://leetcode.com/problems/merge-k-sorted-lists/description/

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
        auto comp = [](ListNode* x, ListNode* y) { return x->val > y->val; };
        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comp)> pq{ comp };

        std::for_each(std::begin(lists), std::end(lists), [&pq](ListNode* e) {
            if (e != nullptr)
            {
                pq.push(e);
            }
        });

        auto head = new ListNode;
        auto last = head;

        while (!pq.empty())
        {
            auto node = pq.top();
            pq.pop();

            if (node->next != nullptr)
            {
                pq.push(node->next);
            }

            last->next = node;
            last = last->next;
        }

        last->next = nullptr;

        return head->next;
    }
};