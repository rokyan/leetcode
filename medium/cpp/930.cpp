// https://leetcode.com/problems/binary-subarrays-with-sum/description/

class Solution
{
public:
    int numSubarraysWithSum(std::vector<int>& nums, int goal)
    {
        const auto n = std::size(nums);

        std::unordered_map<int, int> pref;
        pref[0]++;

        auto res = 0;

        for (auto i = 0, s = 0; i < n; i++)
        {
            s += nums[i];

            if (const auto it = pref.find(s - goal); it != std::end(pref))
            {
                res += it->second;
            }

            pref[s]++;
        }

        return res;
    }
};