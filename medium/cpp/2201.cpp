// https://leetcode.com/problems/count-artifacts-that-can-be-extracted/description/

class Solution
{
public:
    int digArtifacts(int n, std::vector<std::vector<int>>& artifacts, std::vector<std::vector<int>>& dig)
    {
        std::vector<std::vector<char>> grid(n, std::vector<char>(n));

        for (const auto& d : dig)
        {
            grid[d[0]][d[1]] = true;
        }

        auto res = 0;

        for (const auto& ar : artifacts)
        {
            auto valid = true;

            for (auto i = ar[0]; i <= ar[2] && valid; i++)
            {
                for (auto j = ar[1]; j <= ar[3] && valid; j++)
                {
                    if (!grid[i][j])
                    {
                        valid = false;
                    }
                }
            }

            res += valid;
        }

        return res;
    }
};