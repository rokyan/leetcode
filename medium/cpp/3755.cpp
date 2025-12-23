// https://leetcode.com/problems/find-maximum-balanced-xor-subarray-length/description/

class Solution
{
public:
    int maxBalancedSubarray(const std::vector<int>& nums)
    {
        int balance = 0;
        int acc = 0;

        std::map<std::pair<int, int>, int> pref;
        pref[{0, 0}] = -1;

        int res = 0;

        for (int i = 0; i < std::size(nums); i++)
        {
            acc ^= nums[i];

            if (nums[i] % 2 == 1)
            {
                balance++;
            }
            else
            {
                balance--;
            }

            if (const auto it = pref.find({acc, balance}); it == std::cend(pref))
            {
                pref.insert({{acc, balance}, i});
            }
            else
            {
                res = std::max(res, i - it->second);
            }
        }

        return res;
    }
};