https://leetcode.com/problems/sort-list/description/

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
    ListNode* sortList(ListNode* head)
    {
        return sort(head);
    }

private:
    ListNode* sort(ListNode* head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        auto slow = head;
        auto fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        auto next = slow->next;
        slow->next = nullptr;

        return merge(sort(head), sort(next));
    }

    ListNode* merge(ListNode* first, ListNode* second)
    {
        auto head = static_cast<ListNode*>(nullptr);
        auto cur = head;

        auto add = [&head, &cur](ListNode*& node)
        {
            if (head == nullptr)
            {
                head = cur = node;
            }
            else
            {
                cur->next = node;
                cur = cur->next;
            }

            node = node->next;
        };

        while (first != nullptr && second != nullptr)
        {
            if (first->val <= second->val)
            {
                add(first);
            }
            else
            {
                add(second);
            }
        }

        while (first != nullptr)
        {
            add(first);
        }

        while (second != nullptr)
        {
            add(second);
        }

        cur->next = nullptr;

        return head;
    }
};