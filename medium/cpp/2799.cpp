// https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/

class Solution
{
public:
    int countCompleteSubarrays(std::vector<int>& nums)
    {
        const auto tot_un = std::size(std::unordered_set<int>(std::begin(nums), std::end(nums)));

        std::unordered_map<int, int> cnt;

        auto l = 0;
        auto r = 0;

        while (r < std::size(nums))
        {
            cnt[nums[r]]++;

            if (std::size(cnt) == tot_un)
            {
                break;
            }

            r++;
        }

        auto res = 0;

        while (r < std::size(nums))
        {
            while (cnt[nums[l]] > 1)
            {
                cnt[nums[l++]]--;
            }

            res += l + 1;

            r++;

            if (r < std::size(nums))
            {
                cnt[nums[r]]++;
            }
        }

        return res;
    }
};