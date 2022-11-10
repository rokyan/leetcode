// https://leetcode.com/problems/matrix-block-sum/

class Solution
{
public:
    std::vector<std::vector<int>> matrixBlockSum(std::vector<std::vector<int>>& mat, int k)
    {
        const int n = std::size(mat);
        const int m = std::size(mat.front());
        
        std::vector<std::vector<int>> sums(n);
        
        for (int i = 0; i < n; i++)
        {
            sums[i].resize(m);
            
            for (int j = 0; j < m; j++)
            {
                sums[i][j] = mat[i][j];
                
                if (i > 0)
                {
                    sums[i][j] += sums[i - 1][j];
                }
                
                if (j > 0)
                {
                    sums[i][j] += sums[i][j - 1];
                }
                
                if (i > 0 && j > 0)
                {
                    sums[i][j] -= sums[i - 1][j -  1];
                }
            }
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int i0 = std::max(0, i - k);
                int j0 = std::max(0, j - k);
                
                int i1 = std::min(n - 1, i + k);
                int j1 = std::min(m - 1, j + k);
                
                int sum = sums[i1][j1];
                
                if (i0 > 0)
                {
                    sum -= sums[i0 - 1][j1];
                }
                
                if (j0 > 0)
                {
                    sum -= sums[i1][j0 - 1];
                }
                
                if (i0 > 0 && j0 > 0)
                {
                    sum += sums[i0 - 1][j0 - 1];
                }
                
                mat[i][j] = sum;
            }
        }
        
        return mat;
    }
};