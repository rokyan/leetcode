class Solution
{
public:
    int longestOnes(const std::vector<int>& nums, int k)
    {
        auto res = 0;

        for (auto l = 0, r = 0, zeroes = 0; r < std::size(nums); r++)
        {
            if (nums[r] == 0)
            {
                zeroes++;
            }

            while (zeroes == k + 1)
            {
                if (nums[l++] == 0)
                {
                    zeroes--;
                }
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};