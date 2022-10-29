// https://leetcode.com/problems/optimal-partition-of-string/

class Solution
{
public:
    int partitionString(std::string s)
    {
        int cnt[26] = { 0 };
        
        auto ans = 0;
        
        for (char c : s)
        {
            const auto code = c - 'a';
            
            if (cnt[code])
            {
                ans++;
                
                std::fill(std::begin(cnt), std::end(cnt), 0);
            }
            
            cnt[code]++;
        }
        
        return ++ans;
    }
};