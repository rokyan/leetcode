// https://leetcode.com/problems/increment-submatrices-by-one/description/

class Solution
{
public:
    std::vector<std::vector<int>> rangeAddQueries(int n, std::vector<std::vector<int>>& queries)
    {
        std::vector<std::vector<int>> res(n, std::vector<int>(n));

        for (const auto& query : queries)
        {
            const auto row1 = query[0];
            const auto col1 = query[1];
            const auto row2 = query[2];
            const auto col2 = query[3];

            for (auto row = row1; row <= row2; row++)
            {
                res[row][col1]++;

                if (col2 + 1 < n)
                {
                    res[row][col2 + 1]--;
                }
            }
        }

        for (auto row = 0; row < n; row++)
        {
            for (auto col = 1; col < n; col++)
            {
                res[row][col] += res[row][col - 1];
            }
        }

        return res;
    }
};