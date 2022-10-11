// https://leetcode.com/problems/number-of-provinces/

class Solution
{
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected)
    {
        const auto n = std::size(isConnected);
        
        std::vector<bool> visited(n);
        int cnt = 0;
        
        for (int v = 0; v < n; v++)
        {
            if (!visited[v])
            {
                cnt++;
                
                std::queue<int> q;
                q.push(v);
                visited[v] = true;
                
                while (!q.empty())
                {
                    int u = q.front();
                    q.pop();
                    
                    for (int to = 0; to < n; to++)
                    {
                        if (!visited[to] && isConnected[u][to])
                        {
                            visited[to] = true;
                            q.push(to);
                        }
                    }
                }
            }
        }
        
        return cnt;
    }
};