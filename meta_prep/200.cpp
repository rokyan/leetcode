class Solution
{
private:
    class Dsu
    {
    public:
        Dsu(int n)
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
        
    private:
        std::vector<int> parent;
        std::vector<int> size;
    };

public:
   int numIslands(std::vector<std::vector<char>>& grid)
   {
        const int rows = std::size(grid);      
        const int cols = std::size(grid.front());
         
        Dsu dsu{rows * cols};
        
        const std::array<int, 4> di {-1, 0, 1, 0};
        const std::array<int, 4> dj {0, -1, 0, 1};
        
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
                        
                        if (ii >= 0 && ii < rows && jj >= 0 && jj < cols && grid[ii][jj] == '1')
                        {
                            dsu.merge(ii * cols + jj, i * cols + j);
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
                    comps.insert(dsu.find(i * cols + j));
                }
            }
        }
        
        return std::size(comps);
    }
};