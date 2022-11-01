// https://leetcode.com/problems/minimum-height-trees/

class Solution
{
public:
    std::vector<int> findMinHeightTrees(int n, std::vector<std::vector<int>>& edges)
    {   
        build_graph(edges);
        
        std::vector<int> dist(n);
        std::vector<int> parent(n, -1);
        
        dfs(0, -2, 0, dist, parent);
        
        auto v = max_element(std::begin(dist), std::end(dist)) - std::begin(dist);
        
        std::fill(std::begin(parent), std::end(parent), -1);
        
        dfs(v, -2, 0, dist, parent);
        
        auto far_v = max_element(std::begin(dist), std::end(dist)) - std::begin(dist);
        auto diam = dist[far_v];
        
        std::vector<int> answer;
               
        while (far_v != -2)
        {           
            if (dist[far_v] == diam / 2 || dist[far_v] == (diam + 1) / 2)
            {
                answer.push_back(far_v);
            }
            
            far_v = parent[far_v];
        }
        
        return answer;
    }
    
private:
    void build_graph(const std::vector<std::vector<int>>& edges)
    {
        graph.resize(std::size(edges) + 1);
        
        for (const auto& edge : edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
    }
    
    void dfs(int v, int p, int d, std::vector<int>& dist, std::vector<int>& parent)
    {
        dist[v] = d;
        parent[v] = p;
        
        for (auto to : graph[v])
        {
            if (parent[to] == -1)
            {
                dfs(to, v, d + 1, dist, parent);
            }
        }
    }
    
private:
    std::vector<std::vector<int>> graph;
};