class Solution
{
public:
    bool isArraySpecial(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        if (n == 1)
        {
            return true;
        }

        for (auto i = 1; i < n; i++)
        {
            if (((nums[i] ^ nums[i - 1]) & 1) == 0)
            {
                return false;
            }
        }

        return true;
    }
};