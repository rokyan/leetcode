// https://leetcode.com/problems/finding-the-users-active-minutes/

class Solution
{
public:
    std::vector<int> findingUsersActiveMinutes(std::vector<std::vector<int>>& logs, int k)
    {
        std::unordered_map<int, std::unordered_set<int>> user_minutes;
        
        for (const auto& log : logs)
        {
            const auto user_id = log.front();
            const auto minute = log.back();
            
            auto it = user_minutes.find(user_id);
            
            if (it == std::end(user_minutes))
            {
                std::unordered_set<int> minutes;
                minutes.insert(minute);
                
                user_minutes.insert({ user_id, minutes });
            }
            else
            {
                it->second.insert(minute);
            }
        }
        
        std::vector<int> result(k);
        
        for (const auto& user_entry : user_minutes)
        {
            result[std::size(user_entry.second) - 1]++;
        }
        
        return result;
    }
};