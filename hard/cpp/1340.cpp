// https://leetcode.com/problems/jump-game-v/description/

class Solution
{
public:
    int maxJumps(std::vector<int>& arr, int d)
    {
        std::vector<bool> visited(std::size(arr));
        std::vector<int> dist(std::size(arr), -1);
        
        for (std::size_t st {}; st < std::size(arr); st++)
        {
            if (dist[st] == -1)
            {
                std::fill(std::begin(visited), std::end(visited), false);
                visited[st] = true;
                dfs(st, d, arr, visited, dist);
            }
        }

        return *std::max_element(std::begin(dist), std::end(dist));
    }
    
private:
    void dfs(int pos, int d, const std::vector<int>& arr, std::vector<bool>& visited, std::vector<int>& dist)
    {
        if (dist[pos] != -1)
        {
            return;
        }
        
        auto cur_dist = 0;
        
        for (int npos = pos - 1; npos >= 0 && pos - npos <= d && arr[npos] < arr[pos]; npos--)
        {
            if (!visited[npos])
            {
                visited[npos] = true;
                dfs(npos, d, arr, visited, dist);
                cur_dist = std::max(cur_dist, dist[npos]);
                visited[npos] = false;
            }
        }
        
        for (int npos = pos + 1; npos < std::size(arr) && npos - pos <= d && arr[npos] < arr[pos]; npos++)
        {
            if (!visited[npos])
            {
                visited[npos] = true;
                dfs(npos, d, arr, visited, dist);
                cur_dist = std::max(cur_dist, dist[npos]);
                visited[npos] = false;
            }
        }
        
        dist[pos] = cur_dist + 1;
    }
};