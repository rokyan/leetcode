// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution
{
public:
    int makeConnected(int n, std::vector<std::vector<int>>& connections)
    {
        init(n);
        
        int c_count = n;
        int e_count = 0;
        
        for (const auto& edge : connections)
        {
            auto connected = un(edge[0], edge[1]);
            
            if (connected)
            {
                c_count--;
            }
            else
            {
                e_count++;
            }
        }
        
        return (e_count >= c_count - 1) ? c_count - 1 : -1;
    }
    
private:
    void init(std::size_t n)
    {
        parent.resize(n);
        sz.resize(n);
        
        for (std::size_t i = 0; i < n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    
    int find(int u)
    {
        if (u == parent[u])
        {
            return u;
        }
        
        const auto pu = find(parent[u]);
        parent[u] = pu;
        return pu;
    }
    
    bool un(int u, int v)
    {
        auto pu = find(u);
        auto pv = find(v);
        
        if (pu == pv)
        {
            return false;
        }
        
        if (sz[pu] > sz[pv]) std::swap(pu, pv);
        
        parent[pu] = pv;
        sz[pv] += sz[pu];
        
        return true;
    }
    
private:
    std::vector<int> parent;
    std::vector<int> sz;
};