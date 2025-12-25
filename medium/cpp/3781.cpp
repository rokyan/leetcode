// https://leetcode.com/problems/maximum-score-after-binary-swaps/description/

class Solution
{
public:
    long long maximumScore(const std::vector<int>& nums, const std::string& s)
    {
        const int n = std::size(nums);

        std::vector<std::pair<int, int>> v;
        v.reserve(n);

        for (int i = 0; i < n; i++)
        {
            v.emplace_back(nums[i], i);
        }

        std::ranges::sort(v, [](const auto& lhs, const auto& rhs) {
            return lhs.first > rhs.first || lhs.first == rhs.first && lhs.second < rhs.second;
        });

        std::set<int> pos;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                pos.insert(i);
            }
        }

        long long res = 0LL;

        for (int i = 0; i < n; i++)
        {
            const auto [value, p] = v[i];

            if (const auto it = pos.lower_bound(p); it != std::cend(pos))
            {
                res += value;
                pos.erase(it);
            }
        }

        return res;
    }
};