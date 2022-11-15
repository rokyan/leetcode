// https://leetcode.com/problems/number-of-pairs-of-strings-with-concatenation-equal-to-target/

class Solution
{
public:
    int numOfPairs(std::vector<std::string>& nums, std::string target)
    {
        std::unordered_map<std::string_view, int> counts;
        
        for (const auto& num : nums)
        {            
            counts[num]++;
        }
        
        int result = 0;
        
        for (const auto& count_per_num : counts)
        {
            if (is_prefix(count_per_num.first, target))
            {
                const auto view = std::string_view(target).substr(std::size(count_per_num.first));

                const auto it = counts.find(view);

                if (it != std::end(counts))
                {
                    if (count_per_num.first == view)
                    {
                        result += count_per_num.second * (count_per_num.second - 1);
                    }
                    else
                    {
                        result += count_per_num.second * it->second;   
                    }
                }
            }
        }
        
        return result;
    }
    
private:
    bool is_prefix(std::string_view view, const std::string& s) const
    {
        if (std::size(view) > std::size(s))
        {
            return false;
        }
        
        for (std::size_t pos = 0; pos < std::size(view); pos++)
        {
            if (view[pos] != s[pos])
            {
                return false;
            }
        }
        
        return true;
    }
};