// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution
{
public:
    std::vector<int> findSmallestSetOfVertices(int n, std::vector<std::vector<int>>& edges)
    {
        std::vector<std::vector<int>> graph(n);
        
        for (auto e : edges)
        {
            graph[e[0]].push_back(e[1]);
        }
        
        std::vector<bool> used(n);
        std::vector<int> top_sorted;
        
        for (int v = 0; v < n; v++)
        {
            if (!used[v])
            {
                dfs(graph, v, used, top_sorted);
            }
        }
        
        std::reverse(std::begin(top_sorted), std::end(top_sorted));
        
        std::vector<int> result;
        
        std::fill(std::begin(used), std::end(used), false);
        
        for (int v : top_sorted)
        {           
            if (!used[v])
            {
                result.push_back(v);
                dfs2(graph, v, used);
            }
        }
        
        return result;
    }
    
private:
    void dfs(vector<vector<int>>& edges, int v, std::vector<bool>& used, std::vector<int>& top_sorted)
    {
        used[v] = true;
        
        for (auto to : edges[v])
        {
            if (!used[to])
            {
                dfs(edges, to, used, top_sorted);
            }
        }
        
        top_sorted.push_back(v);
    }
    
    void dfs2(vector<vector<int>>& edges, int v, std::vector<bool>& used)
    {
        used[v] = true;
        
        for (auto to : edges[v])
        {
            if (!used[to])
            {
                dfs2(edges, to, used);
            }
        }
    }
};