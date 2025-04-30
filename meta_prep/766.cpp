class Solution
{
public:
    bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix)
    {
        const int n = std::size(matrix);
        const int m = std::size(matrix.front());

        for (auto col = m - 1; col >= 0; col--)
        {
            auto j = col;
            auto i = 0;

            const auto val = matrix[i][j];

            while (j < m && i < n)
            {
                if (val != matrix[i][j])
                {
                    return false;
                }

                i++;
                j++;
            }
        }

        for (auto row = 1; row < n; row++)
        {
            auto i = row;
            auto j = 0;

            const auto val = matrix[i][j];

            while (i < n && j < m)
            {
                if (val != matrix[i][j])
                {
                    return false;
                }

                i++;
                j++;
            }
        }

        return true;
    }
};