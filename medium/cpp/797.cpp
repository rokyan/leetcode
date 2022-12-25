// https://leetcode.com/problems/all-paths-from-source-to-target/description/

class Solution
{
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>>& graph)
    {
        std::vector<std::vector<int>> paths;
        std::vector<int> path;
        
        solve(0, std::size(graph) - 1, path, paths, graph);
        
        return paths;
    }
    
private:    
    void solve(int v, int n, std::vector<int>& path,
        std::vector<std::vector<int>>& paths, const std::vector<std::vector<int>>& graph)
    {
        path.push_back(v);
        
        if (v == n)
        {
            paths.push_back(path);
        }
        else
        {
            for (auto to : graph[v])
            {
                solve(to, n, path, paths, graph);
            }   
        }
        
        path.pop_back();
    }
};