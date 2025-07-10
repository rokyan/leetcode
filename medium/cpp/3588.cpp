// https://leetcode.com/problems/find-maximum-area-of-a-triangle/description/

class Solution
{
public:
    long long maxArea(std::vector<std::vector<int>>& coords)
    {
        const auto n = std::size(coords);

        if (n <= 2)
        {
            return -1;
        }

        auto res = -1LL;

        const auto sortByX = [](const std::vector<int>& left, const std::vector<int>& right)
        {
            return left[0] < right[0];
        };

        std::ranges::sort(coords, sortByX);

        for (auto i = 0; i < n; )
        {
            auto j = i;
            auto maxY = coords[i][1];
            auto minY = coords[i][1];

            while (j < n && coords[j][0] == coords[i][0])
            {
                maxY = std::max(maxY, coords[j][1]);
                minY = std::min(minY, coords[j][1]);
                j++;
            }

            if (j - i > 1)
            {
                auto s = 1LL * (maxY - minY) * (coords.back()[0] - coords[i][0]);
                if (s) res = std::max(res, s);
                s = 1LL * (maxY - minY) * (coords[i][0] - coords.front()[0]);
                if (s) res = std::max(res, s);
            }

            i = j;
        }

        const auto sortByY = [](const std::vector<int>& left, const std::vector<int>& right)
        {
            return left[1] < right[1];
        };

        std::ranges::sort(coords, sortByY);

        for (auto i = 0; i < n; )
        {
            auto j = i;
            auto maxX = coords[i][0];
            auto minX = coords[i][0];

            while (j < n && coords[j][1] == coords[i][1])
            {
                maxX = std::max(maxX, coords[j][0]);
                minX = std::min(minX, coords[j][0]);
                j++;
            }

            if (j - i > 1)
            {
                auto s = 1LL * (maxX - minX) * (coords.back()[1] - coords[i][1]);
                if (s) res = std::max(res, s);
                s = 1LL * (maxX - minX) * ( coords[i][1] - coords.front()[1]);
                if (s) res = std::max(res, s);
            }

            i = j;
        }

        return res;
    }
};