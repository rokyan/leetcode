// https://leetcode.com/problems/max-area-of-island/

class Solution
{
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
    {
        const auto n = std::size(grid);
        const auto m = std::size(grid.front());
        
        std::vector<std::vector<int>> used(n, std::vector<int>(m));
        
        std::vector<int> d_row { 1, 0, -1, 0 };
        std::vector<int> d_col { 0, -1, 0, 1 };
        
        std::queue<std::pair<int, int>> cells;
        
        int answer = 0;
        
        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                if (!used[i][j] && grid[i][j] == 1)
                {
                    cells = {};
                    cells.push({i, j});
                    used[i][j] = 1;
                    
                    int count = 0;
                    
                    while (!cells.empty())
                    {
                        auto cell = cells.front();
                        cells.pop();
                        
                        count++;
                        
                        for (int k = 0; k < 4; k++)
                        {
                            int ii = cell.first + d_row[k];
                            int jj = cell.second + d_col[k];
                            
                            if (ii >= 0 && ii < n && jj >= 0 && jj < m && !used[ii][jj] && grid[ii][jj] == 1)
                            {
                                used[ii][jj] = 1;
                                cells.push({ii, jj});
                            }
                        }
                    }
                
                    if (count > answer)
                    {
                        answer = count;
                    }
                }
            }
        }
        
        return answer;
    }
};