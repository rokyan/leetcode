// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/description/

class Solution
{
public:
    int minOperations(std::vector<int>& nums)
    {
        std::unordered_map<int, int> cnt;

        for (auto num : nums)
        {
            cnt[num]++;
        }

        auto res = 0;

        for (auto&& entry : cnt)
        {
            const auto times = entry.second;

            if (times == 1)
            {
                return -1;
            }

            if (times % 3 == 0)
            {
                res += times / 3;
            }
            else if (times % 3 == 1)
            {
                res += (times - 4) / 3 + 2;
            }
            else
            {
                res += times / 3 + 1;
            }
        }

        return res;
    }
};