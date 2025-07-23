// https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description/

class Solution
{
public:
    bool checkValidCuts(int n, const std::vector<std::vector<int>>& rectangles)
    {
        std::map<int, std::pair<int, int>> xs;
        std::map<int, std::pair<int, int>> ys;

        for (const auto& rec : rectangles)
        {
            xs[rec[0]].first++;
            xs[rec[2]].second++;
            ys[rec[1]].first++;
            ys[rec[3]].second++;
        }

        return solve(xs) || solve(ys);
    }

private:
    bool solve(const std::map<int, std::pair<int, int>>& coord)
    {
        auto balance = 0;
        auto res = -1;

        for (const auto& [_, c] : coord)
        {
            const auto had = balance > 0;
            balance -= c.second;

            if (balance == 0 && had)
            {
                if (++res >= 2)
                {
                    break;
                }
            }

            balance += c.first;
        }

        return res >= 2;
    }
};