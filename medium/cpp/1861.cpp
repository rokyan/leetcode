// https://leetcode.com/problems/rotating-the-box/

class Solution
{
public:
    std::vector<std::vector<char>> rotateTheBox(std::vector<std::vector<char>>& box)
    {
        const auto n = std::size(box);
        const auto m = std::size(box.front());
        
        std::vector<std::vector<char>> rbox(m, std::vector<char>(n));
        
        for (std::size_t i = 0; i < m; i++)
        {
            for (std::size_t j = 0; j < n; j++)
            {
                rbox[i][n - j - 1] = box[j][i];
            }
        }
        
        for (int i = m - 2; i >= 0; i--)
        {
            for (std::size_t j = 0; j < n; j++)
            {
                if (rbox[i][j] == '#' && rbox[i + 1][j] == '.')
                {
                    int k = i;
                    
                    while (k + 1 < m && rbox[k][j] == '#' && rbox[k + 1][j] == '.')
                    {
                        rbox[k + 1][j] = '#';
                        rbox[k][j] = '.';
                        k++;
                    }
                }
            }
        }
        
        return rbox;
    }
};