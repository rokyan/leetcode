// https://leetcode.com/problems/custom-sort-string/

class Solution
{
public:
    std::string customSortString(std::string order, std::string s)
    {
        std::vector<int> weights(26, 1000);
        
        for (std::size_t weight = 0; weight < std::size(order); weight++)
        {
            weights[order[weight] - 'a'] = weight;
        }
        
        for (std::size_t i = 1; i < std::size(s); i++)
        {
            std::size_t j = i;
            
            while (j > 0 && weights[s[j] - 'a'] < weights[s[j - 1] - 'a'])
            {
                std::swap(s[j - 1], s[j]);
                j--;
            }
        }
        
        return s;
    }
};