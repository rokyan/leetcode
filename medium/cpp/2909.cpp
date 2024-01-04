// https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/description/

class Solution
{
public:
    int minimumSum(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> rem(nums);

        for (auto i = static_cast<int>(n) - 2; i >= 0; i--)
        {
            rem[i] = std::min(rem[i], rem[i + 1]);
        }

        auto msf = nums.front();
        auto res = -1;

        for (auto i = 1; i + 1 < n; i++)
        {
            if (msf < nums[i])
            {
                if (rem[i + 1] < nums[i])
                {
                    const auto upd =  msf + nums[i] + rem[i + 1];
                    res = res == -1 ? upd : std::min(res, upd);
                }
            }

            msf = std::min(msf, nums[i]);
        }

        return res;
    }
};