// https://leetcode.com/problems/linked-list-components/

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
    int numComponents(ListNode* head, std::vector<int>& nums)
    {
        const auto len = get_len(head);
        
        std::vector<char> is_comp(len);
        
        for (auto num : nums)
        {
            is_comp[num] = true;
        }
        
        auto count = 0;
        auto is_prev_comp = false;
        
        while (head != nullptr)
        {
            if (is_comp[head->val])
            {
                if (!is_prev_comp)
                {
                    count++;
                }
                
                is_prev_comp = true;
            }
            else
            {
                is_prev_comp = false;
            }
            
            head = head->next;
        }
        
        return count;
    }
    
private:
    int get_len(ListNode* head)
    {
        int len = 0;
        
        while (head != nullptr)
        {
            len++;
            head = head->next;
        }
        
        return len;
    }
};