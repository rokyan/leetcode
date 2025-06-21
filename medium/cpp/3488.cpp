// https://leetcode.com/problems/closest-equal-element-queries/description/

class Solution
{
public:
    std::vector<int> solveQueries(const std::vector<int>& nums, const std::vector<int>& queries)
    {
        std::unordered_map<int, std::vector<int>> posForVal;

        const auto n = std::size(nums);

        for (auto i = 0; i < n; i++)
        {
            posForVal[nums[i]].push_back(i);
        }

        std::vector<int> res;
        res.reserve(std::size(queries));

        for (auto q : queries)
        {
            const auto& posList = posForVal[nums[q]];

            if (std::size(posList) == 1)
            {
                res.push_back(-1);
            }
            else
            {
                const auto pos = std::distance(
                    std::cbegin(posList),
                    std::lower_bound(std::cbegin(posList), std::cend(posList), q));

                const auto back = pos > 0
                    ? q - posList[pos - 1]
                    : 1 + q + (n - 1 - posList.back());
                const auto forward = pos + 1 < std::size(posList)
                    ? posList[pos + 1] - q
                    : 1 + (n - 1 - q) + posList[0];

                res.push_back(std::min(back, forward));
            }
        }

        return res;
    }
};