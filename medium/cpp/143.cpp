// https://leetcode.com/problems/reorder-list/

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
    void reorderList(ListNode* head)
    {
        const auto size = get_size(head);
        
        if (size == 1)
        {
            return;
        }
        
        auto mid = (size + 1) / 2;
                
        ListNode* second = head;
        ListNode* tail = nullptr;
        
        while (mid--)
        {
            tail = second;
            second = second->next;
        }
        
        second = reverse(second);
        tail->next = nullptr;
        
        ListNode* current = head;
        
        while (current != nullptr)
        {
            auto next = current->next;
            
            if (second != nullptr)
            {
                current->next = second;
                auto next_second = second->next;
                second->next = next;
                second = next_second;
            }
            
            current = next;
        }
    }
    
private:
    int get_size(ListNode* node)
    {
        int size = 0;
        
        while (node != nullptr)
        {
            size++;
            node = node->next;
        }
        
        return size;
    }
    
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