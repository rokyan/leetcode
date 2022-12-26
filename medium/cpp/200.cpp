// https://leetcode.com/problems/number-of-islands/description/

class Solution
{
public:
   int numIslands(std::vector<std::vector<char>>& grid)
   {
        const auto rows = std::size(grid);      
        const auto cols = std::size(grid.front());
         
        prep(rows * cols);
        
        const std::array<int, 4> di { -1, 0, 1, 0 };
        const std::array<int, 4> dj { 0, -1, 0, 1 };
        
        for (auto i = 0; i < rows; ++i)
        {
            for (auto j = 0; j < cols; ++j)
            {
                if (grid[i][j] == '1')
                {
                    for (auto k = 0; k < 4; ++k)
                    {
                        const auto ii = i + di[k];
                        const auto jj = j + dj[k];
                        
                        if (check_pos(ii, jj, rows, cols) && grid[ii][jj] == '1')
                        {
                            merge(ii * cols + jj, i * cols + j);
                        }
                    }
                }
            }
        }
        
        std::unordered_set<int> comps;
        
        for (auto i = 0; i < rows; ++i)
        {
            for (auto j = 0; j < cols; ++j)
            {
                if (grid[i][j] == '1')
                {
                    comps.insert(find(i * cols + j));
                }
            }
        }
        
        return std::size(comps);
    }

private:    
    void prep(std::size_t n)
    {
        parent.resize(n);
        size.resize(n);
        
        for (auto i = 0; i < n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int v) const
    {
        if (v != parent[v])
        {
            v = find(parent[v]);
        }
        
        return v;
    }
    
    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        
        if (u != v)
        {
            if (size[u] < size[v])
            {
                std::swap(u, v);
            }
            
            size[u] += size[v];
            parent[v] = u;
        }
    }
    
    bool check_pos(int i, int j, int rows, int cols) const
    {
        return i >= 0 && i < rows && j >= 0 && j < cols;
    }
    
private:
    std::vector<int> parent;
    std::vector<int> size;
};