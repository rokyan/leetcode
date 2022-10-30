// https://leetcode.com/problems/loud-and-rich/

class Solution
{
public:
    std::vector<int> loudAndRich(std::vector<std::vector<int>>& richer, std::vector<int>& quiet)
    {
        const int n = std::size(quiet);
        
        std::vector<std::vector<int>> graph(n);
        
        for (const auto& edge : richer)
        {
            graph[edge[1]].push_back(edge[0]);
        }
        
        std::vector<int> ans(n);        
        std::vector<int> memo(n, -1);
        
        for (int v = 0; v < n; v++)
        {
            ans[v] = dfs(v, graph, quiet, memo);
        }
        
        return ans;
    }
    
private:
    int dfs(int v, const std::vector<std::vector<int>>& graph, const std::vector<int>& quiet, std::vector<int>& memo)
    {
        if (memo[v] != -1)
        {
            return memo[v];
        }
        
        int u = v;
        
        for (auto to : graph[v])
        {
            auto z = dfs(to, graph, quiet, memo);
            
            if (quiet[z] < quiet[u])
            {
                u = z;
            }
        }
        
        memo[v] = u;
        
        return u;
    }
};