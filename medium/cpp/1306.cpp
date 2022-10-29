// https://leetcode.com/problems/jump-game-iii/submissions/

class Solution
{
public:
    bool canReach(vector<int>& arr, int start)
    {
        std::vector<int> visited(std::size(arr));
        
        return dfs(start, visited, arr);
    }
    
private:
    bool dfs(int v, std::vector<int>& visited, const std::vector<int>& arr)
    {
        visited[v] = true;
        
        if (arr[v] == 0)
        {
            return true;
        }
        
        auto res = false;
        
        if (v - arr[v] >= 0 && !visited[v - arr[v]])
        {
            res |= dfs(v - arr[v], visited, arr);
        }
        
        if (!res && v + arr[v] < std::size(visited) && !visited[v + arr[v]])
        {
            res |= dfs(v + arr[v], visited, arr);
        }
        
        return res;
    }
    
private:
    
};