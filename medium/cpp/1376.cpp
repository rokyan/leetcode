// https://leetcode.com/problems/time-needed-to-inform-all-employees/

class Solution
{
public:
    int numOfMinutes(int n, int headID, std::vector<int>& manager, std::vector<int>& informTime)
    {
        std::vector<int> tot(n, -1);
        tot[headID] = informTime[headID];
        
        for (int v = 0; v < n; v++)
        {
            if (tot[v] == -1)
            {
                solve(v, tot, manager, informTime);
            }
        }
        
        return *std::max_element(std::begin(tot), std::end(tot));
    }
    
private:
    void solve(int v, std::vector<int>& tot, const std::vector<int>& manager, const std::vector<int>& informTime)
    {
        const auto u = manager[v];
        
        if (tot[u] == -1)
        {
            solve(u, tot, manager, informTime);
        }
        
        tot[v] = tot[u] + informTime[v];
    }
};