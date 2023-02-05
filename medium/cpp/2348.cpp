// https://leetcode.com/problems/number-of-zero-filled-subarrays/description/

class Solution
{
public:
    long long zeroFilledSubarray(std::vector<int>& nums)
    {
        long long res = 0;

        auto cnt = 0;

        for (auto i = 0; i < std::size(nums); i++)
        {
            if (nums[i] == 0)
            {
                cnt++;
            }
            else
            {
                res += 1LL * cnt * (cnt + 1) / 2;
                cnt = 0;
            }
        }

        res += 1LL * cnt * (cnt + 1) / 2;

        return res;    
    }
};