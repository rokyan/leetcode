// https://leetcode.com/problems/merge-in-between-linked-lists/

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)
    {
        ListNode* node_a = list1;
        
        while (--a)
        {
            node_a = node_a->next;
        }
        
        ListNode* node_b = list1;
        
        while (b--)
        {
            node_b = node_b->next;
        }
        
        node_a->next = list2;
        
        while (list2->next)
        {
            list2 = list2->next;
        }
        
        list2->next = node_b->next;
        
        return list1;
    }
};