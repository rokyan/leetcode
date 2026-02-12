// https://leetcode.com/problems/count-subarrays-with-cost-less-than-or-equal-to-k/description/

class Solution
{
public:
    long long countSubarrays(const std::vector<int>& nums, long long k)
    {
        const int n = nums.size();

        std::multiset<int> range;

        long long res = 0LL;

        for (int l = 0, r = 0; r < n; r++)
        {
            range.insert(nums[r]);

            while (!range.empty() && 1LL * range.size() * (-(*range.begin()) + (*range.rbegin())) > k)
            {
                range.erase(range.find(nums[l++]));
            }

            res += r - l + 1;
        }

        return res;
    }
};