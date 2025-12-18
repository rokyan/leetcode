// https://leetcode.com/problems/line-reflection/description/

class Solution
{
public:
    bool isReflected(const std::vector<std::vector<int>>& points)
    {
        std::unordered_map<int, std::vector<int>> yxs;

        for (const auto& point : points)
        {
            const int x = point[0];
            const int y = point[1];

            yxs[y].push_back(x);
        }

        for (auto& [y, xs] : yxs)
        {
            std::ranges::sort(xs);
            xs.erase(std::unique(std::begin(xs), std::end(xs)), std::end(xs));
        }

        const int mid = std::begin(yxs)->second.front() + std::begin(yxs)->second.back();

        for (auto& [y, xs] : yxs)
        {
            const int n = std::size(xs);

            for (int i = 0; i <= n / 2; i++)
            {
                const int cand_mid = xs[i] + xs[n - i - 1];

                if (cand_mid != mid)
                {
                    return false;
                }
            }
        }

        return true;
    }
};