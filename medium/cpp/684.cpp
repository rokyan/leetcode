// https://leetcode.com/problems/redundant-connection/

class Solution
{
public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>>& edges)
    {
        const auto n = std::size(edges);
        
        init(n);
        
        for (const auto& edge : edges)
        {
            const auto u = edge[0] - 1;
            const auto v = edge[1] - 1;
            
            if (!un(u, v))
            {
                return edge;
            }
        }
        
        return {};
    }
    
private:
    void init(std::size_t n)
    {
        sz.resize(n, 1);
        parent.resize(n);
        
        for (std::size_t v = 0; v < n; v++)
        {
            parent[v] = v;
        }
    }
    
    int find(int v)
    {
        if (v == parent[v])
        {
            return v;
        }
        
        return parent[v] = find(parent[v]);
    }
    
    bool un(int u, int v)
    {
        u = find(u);
        v = find(v);
        
        if (u == v)
        {
            return false;
        }
        
        if (sz[u] > sz[v])
        {
            parent[v] = u;
            sz[u] += sz[v];
        }
        else
        {
            parent[u] = v;
            sz[v] += sz[u];
        }
        
        return true;
    }
    
private:
    std::vector<int> sz;
    std::vector<int> parent;
};