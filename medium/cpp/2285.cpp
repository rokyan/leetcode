// https://leetcode.com/problems/maximum-total-importance-of-roads/

class Solution
{
public:
    long long maximumImportance(int n, std::vector<std::vector<int>>& roads)
    {
        std::vector<int> cnt(n);
        
        for (const auto& road : roads)
        {
            cnt[road[0]]++;
            cnt[road[1]]++;
        }
        
        std::sort(std::begin(cnt), std::end(cnt), std::greater<>());
        
        long long ans = 0;
        
        for (std::size_t i = 0; i < n; i++)
        {
            ans += 1LL * (n - i) * cnt[i];
        }
        
        return ans;
    }
};