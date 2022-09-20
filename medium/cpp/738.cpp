// https://leetcode.com/problems/monotone-increasing-digits/

class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        std::queue<int> q;
        
        for (int num = 1; num <= 9; num++)
        {
            if (num <= n)
            {
                q.push(num);
            }
        }
        
        auto ans = 0;
        
        while (!q.empty())
        {
            const auto num = q.front();
            q.pop();
            
            ans = std::max(ans, num);
            
            const auto last_digit = num % 10;
            
            for (int digit = last_digit; digit <= 9; digit++)
            {
                const auto next_num = 1LL * num * 10 + digit;
                
                if (next_num <= n)
                {
                    q.push(next_num);
                }
            }
        }
        
        return ans;
    }
};