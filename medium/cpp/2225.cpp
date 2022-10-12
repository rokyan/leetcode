// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

class Solution
{
public:
    std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches)
    {
        std::unordered_map<int, int> data;
        
        for (const auto& match : matches)
        {
            const auto winner = match[0];
            const auto loser = match[1];
            
            const auto w_it = data.find(winner);
            
            if (w_it == std::end(data))
            {
                data[winner] = 0;
            }
            
            const auto l_it = data.find(loser);
            
            if (l_it == std::end(data))
            {
                data[loser] = 1;
            }
            else
            {
                data[loser]++;
            }
        }
        
        std::vector<std::vector<int>> res(2);
        
        for (int i = 0; i < 2; i++)
        {
            res[i].reserve(std::size(data));
        }
        
        for (const auto& entry : data)
        {
            if (entry.second == 0)
            {
                res[0].push_back(entry.first);
            }
            else if (entry.second == 1)
            {
                res[1].push_back(entry.first);
            }
        }
        
        for (int i = 0; i < 2; i++)
        {
            std::sort(std::begin(res[i]), std::end(res[i]));
        }
        
        return res;
    }
};