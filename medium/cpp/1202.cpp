// https://leetcode.com/problems/smallest-string-with-swaps/

class Solution
{
public:
    std::string smallestStringWithSwaps(std::string s, std::vector<std::vector<int>>& pairs)
    {
        const auto n = std::size(s);

        init(n);
        
        int cp = n;
        
        for (const auto& e : pairs)
        {
            if (un(e[0], e[1]))
            {
                cp--;
            }
        }
        
        std::vector<std::string> ss(n);
        std::vector<int> pt(n);
        
        for (int i = 0; i < n; i++)
        {
            auto p = find(i);
            ss[p] += s[i];
        }
        
        for (auto& e : ss)
        {
            std::sort(std::begin(e), std::end(e));
        }
        
        for (int i = 0; i < n; i++)
        {
            auto p = find(i);
            s[i] = ss[p][pt[p]++];
        }
        
        return s;
    }
    
private:
    void init(int n)
    {
        parent.resize(n);
        size.resize(n);
        
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int v)
    {
        if (v == parent[v])
        {
            return v;
        }
        
        auto p = find(parent[v]);
        parent[v] = p;
        
        return p;
    }
    
    bool un(int v, int u)
    {
        auto pv = find(v);
        auto pu = find(u);
        
        if (pu == pv)
        {
            return false;
        }
        
        if (size[pv] < size[pu])
        {
            std::swap(pv, pu);
        }
        
        parent[pu] = pv;
        size[pv] += size[pu];
        
        return true;
    }
    
private:
    std::vector<int> parent;
    std::vector<int> size;
};