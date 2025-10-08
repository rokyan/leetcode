class Solution
{
public:
    std::vector<int> smallestRange(const std::vector<std::vector<int>>& nums)
    {
        std::vector<std::pair<int, int>> v;
        v.reserve(std::size(nums) * 50);

        for (auto i = 0; i < std::size(nums); i++)
        {
            for (auto e : nums[i])
            {
                v.emplace_back(e, i);
            }
        }

        std::ranges::sort(v);

        std::vector<int> freq(std::size(nums));
        auto cnt = 0;

        std::vector<int> res;

        for (auto r = 0, l = 0; r < std::size(v); r++)
        {
            if (freq[v[r].second]++ == 0)
            {
                cnt++;
            }

            while (cnt == std::size(nums) && freq[v[l].second] > 1)
            {
                freq[v[l++].second]--;
            }

            if (cnt == std::size(nums))
            {
                if (res.empty() || res.back() - res.front() > v[r].first - v[l].first)
                {
                    res = {v[l].first, v[r].first};
                }
            }
        }

        return res;
    }
};