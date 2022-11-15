// https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution
{
public:
    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>>& mat)
    {
        const int m = std::size(mat);
        const int n = std::size(mat.front());
        
        for (int start_i = 0; start_i < m; start_i++)
        {
            for (int start_j = 0; start_j < n; start_j++)
            {
                if (start_i == 0 || start_j == 0)
                {
                    int end_i = start_i;
                    int end_j = start_j;

                    while (end_i < m && end_j < n)
                    {
                        end_i++;
                        end_j++;
                    }
                    
                    int i = start_i;
                    int j = start_j;
                    
                    while (i < end_i && j < end_j)
                    {
                        int ii = i;
                        int jj = j;

                        while (ii > 0 && jj > 0 && mat[ii][jj] < mat[ii - 1][jj - 1])
                        {
                            std::swap(mat[ii][jj], mat[ii - 1][jj - 1]);
                            ii--;
                            jj--;
                        }
                        
                        i++;
                        j++;
                    }
                }
            }
        }

        return mat;
    }
};