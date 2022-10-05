// https://leetcode.com/problems/find-all-groups-of-farmland/

class Solution
{
public:
    std::vector<std::vector<int>> findFarmland(std::vector<std::vector<int>>& land)
    {
        const int n = std::size(land);
        const int m = std::size(land.front());
        
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m));
        
        std::vector<std::vector<int>> ans;
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && land[i][j])
                {
                    std::vector<int> group { n, m, 0, 0 };
                    dfs(i, j, n, m, land, visited, group);
                    ans.push_back(group);
                }
            }
        }
        
        return ans;
    }
    
private:
    void dfs(int i, int j, int n, int m, const std::vector<std::vector<int>>& land,
        std::vector<std::vector<bool>>& visited, std::vector<int>& group)
    {
        if (i < 0 || i == n || j < 0 || j == m || visited[i][j] || land[i][j] == 0)
        {
            return;
        }
        
        if (i <= group[0] && j <= group[1])
        {
            group[0] = i;
            group[1] = j;
        }
        
        if (i >= group[2] && j >= group[3])
        {
            group[2] = i;
            group[3] = j;
        }
        
        visited[i][j] = true;
        
        dfs(i + 1, j, n, m, land, visited, group);
        dfs(i - 1, j, n, m, land, visited, group);
        dfs(i, j + 1, n, m, land, visited, group);
        dfs(i, j - 1, n, m, land, visited, group);
    }
};