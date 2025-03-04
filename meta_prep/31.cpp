class Solution 
{
public:
    void nextPermutation(std::vector<int>& nums)
    {
        const int n = std::size(nums);
        auto p = n - 1;

        while (p > 0 && nums[p - 1] >= nums[p])
        {
            p--;
        }

        const auto prev = p - 1;

        if (prev >= 0)
        {
            p = n - 1;

            while (p > prev && nums[p] <= nums[prev])
            {
                p--;
            }

            std::swap(nums[prev], nums[p]);
        }

        std::reverse(std::begin(nums) + prev + 1, std::end(nums));
    }
};