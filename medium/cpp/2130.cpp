// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

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
    int pairSum(ListNode* head)
    {
        auto half_head = head;
        auto fast = head;
        
        while (fast != nullptr && fast->next != nullptr)
        {
            half_head = half_head->next;
            fast = fast->next->next;
        }
        
        half_head = reverse(half_head);
        
        int result = 0;
        
        while (half_head != nullptr)
        {
            result = std::max(result, head->val + half_head->val);
            head = head->next;
            half_head = half_head->next;
        }
        
        return result;
    }

private:   
    ListNode* reverse(ListNode* node)
    {
        ListNode* head = nullptr;
        
        while (node != nullptr)
        {
            auto next = node->next;
            node->next = head;
            head = node;
            node = next;
        }
        
        return head;
    }
};