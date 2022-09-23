// https://leetcode.com/problems/push-dominoes/

class Solution
{
private:
    static constexpr int INF = 1000 * 1000 + 1;
    
public:
    std::string pushDominoes(std::string dominoes)
    {
        const auto n = std::size(dominoes);
        
        std::vector<int> time(n, INF);
        
        std::queue<int> q;
        
        for (std::size_t i = 0; i < n; i++)
        {
            if (dominoes[i] != '.')
            {
                q.push(i);
                time[i] = 0;
            }
        }
        
        while (!q.empty())
        {
            const auto pos = q.front();
            q.pop();
            
            if (dominoes[pos] == '.')
            {
                continue;
            }
            
            if (dominoes[pos] == 'L' && pos > 0)
            {
                if (time[pos - 1] == time[pos] + 1)
                {
                    if (dominoes[pos - 1] == 'R')
                    {
                        dominoes[pos - 1] = '.';
                    }
                }
                else if (time[pos - 1] == INF)
                {
                    time[pos - 1] = time[pos] + 1;
                    dominoes[pos - 1] = 'L';
                    q.push(pos - 1);
                }
            }
            
            if (dominoes[pos] == 'R' && pos + 1 < n)
            {
                if (time[pos + 1] == time[pos] + 1)
                {
                    if (dominoes[pos + 1] == 'L')
                    {
                        dominoes[pos + 1] = '.';
                    }
                }
                else if (time[pos + 1] == INF)
                {
                    time[pos + 1] = time[pos] + 1;
                    dominoes[pos + 1] = 'R';
                    q.push(pos + 1);
                }
            }
        }
        
        return dominoes;
    }
};