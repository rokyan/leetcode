// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/

class Solution
{
public:
    int minGroups(std::vector<std::vector<int>>& intervals)
    {
        std::map<int, int> cnt;

        for (const auto& interval : intervals)
        {
            cnt[interval[0]]++;
            cnt[interval[1] + 1]--;
        }

        auto ans = 0;
        auto cur = 0;

        for (const auto& entry : cnt)
        {
            cur += entry.second;
            ans = std::max(ans, cur);
        }

        return ans;
    }
};