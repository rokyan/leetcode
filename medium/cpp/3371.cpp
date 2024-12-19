// https://leetcode.com/problems/identify-the-largest-outlier-in-an-array/description/

class Solution
{
public:
    int getLargestOutlier(const std::vector<int>& nums)
    {
        std::multiset<int> all(std::cbegin(nums), std::cend(nums));

        const auto sum = std::accumulate(std::cbegin(nums), std::cend(nums), 0);

        std::optional<int> res;

        for (auto num : nums)
        {
            const auto cur = sum - num;
            all.erase(all.find(num));

            if (cur % 2 == 0)
            {
                const auto it = all.find(cur / 2);

                if (it != std::end(all))
                {
                    res = res ? std::max(res.value(), num) : num;
                }
            }

            all.insert(num);
        }

        return res.value();
    }
};