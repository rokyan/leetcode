// https://leetcode.com/problems/number-of-good-ways-to-split-a-string/

class Solution
{
private:
    static constexpr std::size_t ALPH_SIZE = 26;
    
public:
    int numSplits(std::string s)
    {
        std::vector<int> suffix_counts(ALPH_SIZE);
        
        int diff_on_suffix = 0;
        
        for (std::size_t pos = 0; pos < std::size(s); pos++)
        {
            if (suffix_counts[s[pos] - 'a']++ == 0)
            {
                diff_on_suffix++;
            }
        }
               
        std::vector<int> prefix_counts(ALPH_SIZE);
        
        int diff_on_prefix = 0;
        
        int count = 0;
        
        for (std::size_t pos = 0; pos + 1 < std::size(s); pos++)
        {
            if (--suffix_counts[s[pos] - 'a'] == 0)
            {
                diff_on_suffix--;
            }
            
            if (prefix_counts[s[pos] - 'a']++ == 0)
            {
                diff_on_prefix++;
            }
            
            count += diff_on_prefix == diff_on_suffix;
        }
        
        return count;
    }
};