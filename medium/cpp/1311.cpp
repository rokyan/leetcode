// https://leetcode.com/problems/get-watched-videos-by-your-friends/submissions/

class Solution
{
public:
    std::vector<std::string> watchedVideosByFriends(std::vector<std::vector<std::string>>& watchedVideos,
        std::vector<std::vector<int>>& friends, int id, int level)
    {
        const auto n = std::size(friends);
        
        std::vector<int> levels(n, -1);
        levels[id] = 0;
        
        std::queue<int> q;
        q.push(id);
        
        std::vector<int> friends_on_a_level;
        
        while (!q.empty())
        {
            const auto id = q.front();
            q.pop();
            
            if (levels[id] == level)
            {
                friends_on_a_level.push_back(id);
            }
            
            for (auto to : friends[id])
            {
                if (levels[to] == -1)
                {
                    levels[to] = levels[id] + 1;
                    q.push(to);
                }
            }
        }
        
        std::unordered_map<std::string, int> counts;
        
        for (auto id : friends_on_a_level)
        {
            for (auto video : watchedVideos[id])
            {
                counts[video]++;
            }
        }
        
        std::vector<std::pair<int, std::string>> videos_with_counts;
        videos_with_counts.reserve(std::size(counts));
        
        for (const auto& entry : counts)
        {
            videos_with_counts.emplace_back(entry.second, entry.first);
        }
        
        std::sort(std::begin(videos_with_counts), std::end(videos_with_counts));
        
        std::vector<std::string> ans;
        ans.reserve(std::size(videos_with_counts));
        
        for (const auto& entry : videos_with_counts)
        {
            ans.push_back(entry.second);
        }
        
        return ans;
    }
};