class Solution
{
public:
    int findUnsortedSubarray(std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));

        if (n <= 1)
        {
            return 0;
        }

        auto left = 0;
        auto right = n - 1;

        while (left + 1 < n && nums[left] <= nums[left + 1])
        {
            left++;
        }

        while (right > 0 && nums[right] >= nums[right - 1])
        {
            right--;
        }

        if (left > right)
        {
            return 0;
        }

        const auto min = *std::min_element(std::begin(nums) + left, std::begin(nums) + right + 1);
        const auto max = *std::max_element(std::begin(nums) + left, std::begin(nums) + right + 1);

        while (left > 0 && nums[left - 1] > min)
        {
            left--;
        }

        while (right + 1 < n && nums[right + 1] < max)
        {
            right++;
        }

        return right - left + 1;
    }
};