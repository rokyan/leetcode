// https://leetcode.com/problems/maximum-matrix-sum/description/

class Solution
{
public:
    long long maxMatrixSum(const std::vector<std::vector<int>>& matrix)
    {
        const auto n = std::size(matrix);
        const auto m = std::size(matrix.front());

        auto posSum = 0LL;
        auto negSum = 0LL;
        auto zeroes = 0;
        auto negCnt = 0;
        auto posVal = 0;
        auto negVal = 0;

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeroes++;
                }
                else if (matrix[i][j] > 0)
                {
                    posSum += matrix[i][j];
                    posVal = posVal == 0
                        ? matrix[i][j] : std::min(posVal, matrix[i][j]);
                }
                else
                {
                    negSum += matrix[i][j];
                    negCnt++;
                    negVal = negVal == 0
                        ? matrix[i][j] : std::max(negVal, matrix[i][j]);
                }
            }
        }

        if (zeroes > 0)
        {
            return posSum - negSum;
        }

        if (negCnt % 2 == 0)
        {
            return posSum - negSum;
        }

        auto res = posSum - negSum + 2 * negVal;

        if (posVal > 0)
        {
            res = std::max(res, posSum - negSum - 2 * posVal);
        }

        return res;
    }
};