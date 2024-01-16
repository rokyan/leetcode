// https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/description/

class Solution
{
public:
    int longestSubarray(std::vector<int>& nums, int limit)
    {
        std::multiset<int> s;

        auto get_diff = [&s]() {
            return std::abs(*std::cbegin(s) - *std::crbegin(s));
        };

        auto res = 0;

        for (auto l = 0, r = 0; r < std::size(nums); r++)
        {
            s.insert(nums[r]);

            while (get_diff() > limit)
            {
                s.erase(s.find(nums[l++]));
            }

            res = std::max(res, r - l + 1);
        }

        return res;
    }
};