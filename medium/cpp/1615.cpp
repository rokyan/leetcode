// https://leetcode.com/problems/maximal-network-rank/

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        std::vector<std::vector<bool>> is_conn(n);
        
        for (auto& e : is_conn)
        {
            e.resize(n);
        }
        
        std::vector<int> count(n);
        
        for (const auto& edge : roads)
        {
            const auto u = edge[0];
            const auto v = edge[1];
            
            is_conn[u][v] = is_conn[v][u] = true;
            
            count[u]++;
            count[v]++;
        }
        
        int ans = 0;
        
        for (int u = 0; u + 1 < n; u++)
        {
            for (int v = u + 1; v < n; v++)
            {
                ans = std::max(ans, count[u] + count[v] - is_conn[u][v]);
            }
        }
        
        return ans;
    }
};