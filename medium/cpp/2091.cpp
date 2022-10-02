// https://leetcode.com/problems/removing-minimum-and-maximum-from-array/

class Solution
{
public:
    int minimumDeletions(std::vector<int>& nums)
    {
        const int n = std::size(nums);
        
        const auto it_pair = std::minmax_element(std::begin(nums), std::end(nums));
        
        int min_idx = it_pair.first - std::begin(nums);
        int max_idx = it_pair.second - std::begin(nums);
        
        if (min_idx > max_idx)
        {
            std::swap(min_idx, max_idx);
        }
        
        return std::min({ min_idx + n - max_idx + 1, max_idx + 1, n - min_idx});
    }
};