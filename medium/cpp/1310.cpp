// https://leetcode.com/problems/xor-queries-of-a-subarray/description/

class Solution
{
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries)
    {
        std::vector<int> partials(arr);
        
        for (std::size_t i = 1; i < std::size(arr); i++)
        {
            partials[i] ^= partials[i - 1];
        }
        
        std::vector<int> results;
        results.reserve(std::size(queries));
        
        for (const auto& query : queries)
        {
            const auto left = query[0];
            const auto right = query[1];
            
            auto result = partials[right];
            
            if (left > 0)
            {
                result ^= partials[left - 1];
            }
            
            results.push_back(result);
        }
        
        return results;
    }
};