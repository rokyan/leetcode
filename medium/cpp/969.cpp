// https://leetcode.com/problems/pancake-sorting/

class Solution
{
public:
    std::vector<int> pancakeSort(std::vector<int>& arr)
    {
        const auto arr_size = std::size(arr);
        
        if (arr_size == 1)
        {
            return {};
        }
        
        std::vector<int> ops;
        ops.reserve(2 * arr_size);
        
        for (std::size_t rem = arr_size; rem > 1; rem--)
        {
            auto pos = std::max_element(std::begin(arr), std::begin(arr) + rem) - std::begin(arr);
            ops.push_back(pos + 1);
            std::reverse(std::begin(arr), std::begin(arr) + pos + 1);
            ops.push_back(rem);
            std::reverse(std::begin(arr), std::begin(arr) + rem);
        }
        
        return ops;
    }
};