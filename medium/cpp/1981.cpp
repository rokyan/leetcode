// https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/description/

class Solution
{
public:
    int minimizeTheDifference(const std::vector<std::vector<int>>& mat, int target)
    {
        const auto n = std::size(mat);
        const auto m = std::size(mat.front());

        std::vector<char> dp(5000);

        for (auto e : mat.front())
        {
            dp[e] = true;
        }

        for (auto r = 1; r < n; r++)
        {
            std::vector<char> ndp(5000);

            for (auto c = 0; c < m; c++)
            {
                for (auto val = mat[r][c]; val < 5000; val++)
                {
                    if (dp[val - mat[r][c]])
                    {
                        ndp[val] = true;
                    }
                }
            }

            dp = std::move(ndp);
        }

        auto res = 5000;

        for (auto val = 0; val < 5000; val++)
        {
            if (dp[val])
            {
                res = std::min(res, std::abs(target - val));
            }
        }

        return res;
    }
};