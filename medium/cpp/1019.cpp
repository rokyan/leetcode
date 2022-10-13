// https://leetcode.com/problems/next-greater-node-in-linked-list/

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
    std::vector<int> nextLargerNodes(ListNode* head)
    {
        ListNode* node = head;
        ListNode* rev_head = nullptr;
        
        while (node != nullptr)
        {
            ListNode* next = node->next;
            node->next = rev_head;
            rev_head = node;
            node = next;
        }
        
        std::vector<int> res;
        std::vector<int> st;
        
        while (rev_head != nullptr)
        {
            while (!st.empty() && st.back() <= rev_head->val)
            {
                st.pop_back();
            }
            
            res.push_back(st.empty() ? 0 : st.back());
            st.push_back(rev_head->val);
            rev_head = rev_head->next;
        }
        
        std::reverse(std::begin(res), std::end(res));
        
        return res;
    }
};