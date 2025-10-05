class Solution
{
public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix)
    {
        int n = std::size(matrix);
        int m = std::size(matrix.front());
        const int total = n * m;

        int taken = 0;
        int dir = 1;
        std::vector<int> res(n * m);

        int row = 0;
        int col = -1;

        while (taken < total)
        {
            for (int i = 0; i < m; i++)
            {
                col += dir;
                res[taken++] = matrix[row][col];
            }
            n--;

            for (int i = 0; i < n; i++)
            {
                row += dir;
                res[taken++] = matrix[row][col];
            }
            m--;

            dir *= -1;
        }

        return res;
    }
};