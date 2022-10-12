// https://leetcode.com/problems/keys-and-rooms/

class Solution
{
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms)
    {
        const std::size_t n = std::size(rooms);
        visited.resize(n);
        
        dfs(0, rooms);
        
        return std::all_of(std::begin(visited), std::end(visited), [](auto e) { return e; });
    }
    
private:
    void dfs(int v, const std::vector<std::vector<int>>& graph)
    {
        visited[v] = true;
        
        for (auto to : graph[v])
        {
            if (!visited[to])
            {
                dfs(to, graph);
            }
        }
    }
    
private:
    std::vector<bool> visited;
};