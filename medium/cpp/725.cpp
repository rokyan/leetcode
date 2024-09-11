// https://leetcode.com/problems/split-linked-list-in-parts/description/

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
    std::vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        auto len = 0;
        auto node = head;

        while (node != nullptr)
        {
            len++;
            node = node->next;
        }

        const auto s = len / k;
        auto rem = len % k;

        node = head;
        ListNode* prev = nullptr;
        std::vector<ListNode*> res;
        res.reserve(k);

        while (node != nullptr)
        {
            res.push_back(node);

            for (auto i = 0; i < (s + (rem != 0)); i++)
            {
                prev = node;
                node = node->next;
            }

            if (rem)
            {
                rem--;
            }

            prev->next = nullptr;
        }

        while (std::size(res) < k)
        {
            res.push_back(nullptr);
        }

        return res;
    }
};