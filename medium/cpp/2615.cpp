// https://leetcode.com/problems/sum-of-distances/description/

class Solution
{
public:
    std::vector<long long> distance(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::unordered_map<int, std::pair<int, int>> last;

        std::vector<long long> dpl(n), dpr(n);

        for (auto i = 0; i < n; i++)
        {
            if (const auto it = last.find(nums[i]); it != std::end(last))
            {
                dpl[i] = dpl[it->second.second] + 1LL * (i - it->second.second) * it->second.first;
                it->second = { it->second.first + 1, i };
            }
            else
            {
                last[nums[i]] = { 1, i };
            }
        }

        last.clear();

        for (auto i = static_cast<int>(n) - 1; i >= 0; i--)
        {
            if (const auto it = last.find(nums[i]); it != std::end(last))
            {
                dpr[i] = dpr[it->second.second] + 1LL * (it->second.second - i) * it->second.first;
                it->second = { it->second.first + 1, i };
            }
            else
            {
                last[nums[i]] = { 1, i };
            }
        }

        std::vector<long long> res(n);

        std::transform(std::begin(dpl), std::end(dpl), std::begin(dpr), std::begin(res), std::plus<>{});

        return res;
    }
};