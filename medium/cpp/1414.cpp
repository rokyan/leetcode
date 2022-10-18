// https://leetcode.com/problems/find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k/

class Solution
{
public:
    int findMinFibonacciNumbers(int k)
    {
        std::vector<int> fibs { 1, 1 };
       
        std::size_t fibs_count = 2;
        
        while (fibs[fibs_count - 1] < k)
        {
            const auto fib = fibs[fibs_count - 1] + fibs[fibs_count - 2];
            fibs.push_back(fib);
            fibs_count++;
        }
        
        auto ans = 0;
        
        for (int i = fibs_count - 1; i > 0; i--)
        {
            if (k >= fibs[i])
            {
                ans += k / fibs[i];
                k %= fibs[i];
            }
            
            if (k == 0)
            {
                break;
            }
        }
        
        return ans;
    }
};