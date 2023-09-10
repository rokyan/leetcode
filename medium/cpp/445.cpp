// https://leetcode.com/problems/add-two-numbers-ii/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:   
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto first = convert(l1);
        auto second = convert(l2);
        
        auto carry = 0;
        
        std::vector<int> sum;
        
        while (!first.empty() || !second.empty() || carry > 0)
        {
            auto first_dig = 0;
            
            if (!first.empty())
            {
                first_dig = first.back();
                first.pop_back();
            }
            
            auto second_dig = 0;
            
            if (!second.empty())
            {
                second_dig = second.back();
                second.pop_back();
            }
            
            auto digit = first_dig + second_dig + carry;
            carry = digit / 10;
            digit %= 10;
            
            sum.push_back(digit);
        }

        ListNode* node = nullptr;
        ListNode* head = nullptr;
        
        while (!sum.empty())
        {
            if (node == nullptr)
            {
                node = new ListNode { sum.back() };
            }
            else
            {
                node = node->next = new ListNode { sum.back() };
            }
            
            if (head == nullptr)
            {
                head = node;
            }
            
            sum.pop_back();
        }
        
        return head;
    }

private:
    std::vector<int> convert(ListNode* node)
    {
        std::vector<int> st;
        
        for (; node != nullptr; node = node->next)
        {
            st.push_back(node->val);
        }
        
        return st;
    }
};