// https://leetcode.com/problems/sum-of-beauty-of-all-substrings/

class Solution
{
public:
    int beautySum(std::string s)
    {
        const auto n = static_cast<int>(std::size(s));      
       
        int sum = 0;
        
        std::vector<int> counts(26);
        
        for (std::size_t i = 0; i < n; i++)
        {
            std::fill(std::begin(counts), std::end(counts), 0);
            
            auto max_count = 0;
                       
            for (std::size_t j = i; j < n; j++)
            {
                const auto c = s[j] - 'a';                
                counts[c]++;
                
                max_count = std::max(max_count, counts[c]);
                
                auto min_count = n + 1;                
                
                for (int k = 0; k < 26; k++)
                {
                    if (counts[k] == 0)
                    {
                        continue;
                    }
                                       
                    min_count = std::min(min_count, counts[k]);
                }
                
                sum += max_count - min_count;
            }
        }
        
        return sum;
    }
};