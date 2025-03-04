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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        auto fast = head;
        auto slow = head;
        auto prev = static_cast<ListNode*>(nullptr);

        while (n--)
        {
            fast = fast->next;
        }

        while (fast != nullptr)
        {
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }

        if (prev == nullptr)
        {
            return slow->next;
        }
        
        prev->next = slow->next;

        return head;
    }
};