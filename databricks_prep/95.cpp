class Solution
{
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums)
    {
        const int n = std::size(nums);

        for (int i = 0, j = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                std::swap(nums[i], nums[j++]);
            }
        }

        return nums;
    }
};