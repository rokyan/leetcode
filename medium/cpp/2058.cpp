// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

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
    std::vector<int> nodesBetweenCriticalPoints(ListNode* head)
    {
        auto prev = head;
        auto curr = head->next;
        auto next = head->next->next;
        
        int pos = 1;
        int last = -1;
        int first = -1;
        
        std::vector<int> ans { 100000 + 1, -1 };
        
        int cnt = 0;
        
        while (next != nullptr)
        {           
            if (prev->val > curr->val && curr->val < next->val ||
                prev->val < curr->val && curr->val > next->val)
            {
                if (last != -1)
                {
                    const int dist = pos - last;
                    
                    ans[0] = std::min(ans[0], dist);
                    ans[1] = std::max(ans[1], dist);
                }
                
                if (first != -1)
                {
                    const int dist = pos - first;
                    
                    ans[0] = std::min(ans[0], dist);
                    ans[1] = std::max(ans[1], dist);
                }
                
                if (first == -1)
                {
                    first = pos;
                }
                
                last = pos;
                
                cnt++;
            }
            
            pos++;
            prev = curr;
            curr = next;
            next = next->next;
        }
        
        if (cnt >= 2)
        {
            return ans;
        }
        
        return { -1, -1 };
    }
};