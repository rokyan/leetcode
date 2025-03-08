class Solution
{
public:
    int removeDuplicates(std::vector<int>& nums)
    {
        const auto n = std::size(nums);
        auto idx = 1;

        for (auto i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[idx++] = nums[i];
            }
        }

        return idx;
    }
};