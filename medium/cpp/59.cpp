// https://leetcode.com/problems/spiral-matrix-ii/description/

class Solution
{
public:
    std::vector<std::vector<int>> generateMatrix(int n)
    {
        std::array<int, 4> di { 0, 1, 0, -1 };
        std::array<int, 4> dj { 1, 0, -1, 0 };
        
        std::vector<std::vector<int>> mat(n, std::vector<int>(n));
        
        auto i_min = -1;
        auto i_max = n;

        auto j_min = -1;
        auto j_max = n;
        
        for (auto cnt = 1, i = 0, j = 0, dir = 0; cnt <= n * n; cnt++)
        {
            mat[i][j] = cnt;
            
            auto ii = i + di[dir];
            auto jj = j + dj[dir];
            
            const auto valid = ii > i_min && ii < i_max && jj > j_min && jj < j_max;
            
            if (!valid)
            {
                if (dir == 0)
                {
                    i_min = ii;
                }
                
                if (dir == 1)
                {
                    j_max = jj;
                }
                
                if (dir == 2)
                {
                    i_max = ii;
                }
                
                if (dir == 3)
                {
                    j_min = jj;
                }
                
                dir = (dir + 1) % 4;
            }
            
            i += di[dir];
            j += dj[dir];
        }
        
        return mat;
    }
};