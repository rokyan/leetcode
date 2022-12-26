// https://leetcode.com/problems/count-primes/description/

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n <= 1)
        {
            return 0;
        }
        
        std::vector<char> is_prime(n, true);
        
        int answer = 0;
        
        for (int i = 2; i < n; ++i)
        {
            if (is_prime[i])
            {
                answer++;
                
                for (long long j = 1LL * i * i; j < n; j += i)
                {
                    is_prime[j] = false;
                }
            }
        }
        
        return answer;
    }
};