// https://leetcode.com/problems/longest-substring-of-all-vowels-in-order/

class Solution
{
public:
    int longestBeautifulSubstring(string word)
    {
        std::vector<char> let { 'a', 'e', 'i', 'o', 'u' };
        
        std::vector<int> cnt(5);
        
        auto ans = 0;
        
        for (std::size_t pos = 0; pos < std::size(word); )
        {           
            std::fill(std::begin(cnt), std::end(cnt), 0);
            
            for (int i = 0; i < 5; i++)
            {
                while (pos < std::size(word) && word[pos] == let[i])
                {
                    cnt[i]++;
                    pos++;
                }    
            }
            
            const auto all = std::all_of(std::begin(cnt), std::end(cnt), [](auto e) { return e > 0; });
            
            if (all)
            {
                const auto sum = std::accumulate(std::begin(cnt), std::end(cnt), 0);
                
                ans = std::max(ans, sum);
            }
        }
        
        return ans;
    }
};