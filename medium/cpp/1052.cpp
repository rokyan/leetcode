// https://leetcode.com/problems/grumpy-bookstore-owner/

class Solution
{
public:
    int maxSatisfied(std::vector<int>& customers, std::vector<int>& grumpy, int minutes)
    {        
        const int n = std::size(customers);
        
        int answer = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (!grumpy[i])
            {
                answer += customers[i];
            }
        }
        
        int balance = 0;
        int max_balance = 0;
        
        for (int i = 0; i < minutes; i++)
        {
            if (grumpy[i])
            {
                balance += customers[i];
            }
            
            max_balance = std::max(max_balance, balance);
        }
        
        for (int i = minutes; i < n; i++)
        {
            if (grumpy[i - minutes])
            {
                balance -= customers[i - minutes];   
            }
            
            if (grumpy[i])
            {
                balance += customers[i];   
            }
            
            max_balance = std::max(max_balance, balance);
        }
        
        return answer + max_balance;
    }
};