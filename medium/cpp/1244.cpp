// https://leetcode.com/problems/design-a-leaderboard/description/

class Leaderboard
{
public:
    Leaderboard()
    {        
    }
    
    void addScore(int player_id, int score)
    {
        if (const auto it = player_id_to_entry.find(player_id); it != std::end(player_id_to_entry))
        {
            const auto old_score = *it->second;
            scores.erase(it->second);
            it->second = scores.insert(old_score + score);
        }
        else
        {
            player_id_to_entry.emplace(player_id, scores.insert(score));
        }
    }
    
    int top(int k)
    {
        auto s = 0;

        for (auto it = std::cbegin(scores); it != std::cend(scores) && k; k--)
        {
            s += *it++;
        }

        return s;
    }
    
    void reset(int player_id)
    {
        if (const auto it = player_id_to_entry.find(player_id); it != std::end(player_id_to_entry))
        {
            scores.erase(it->second);
            player_id_to_entry.erase(it);
        }        
    }

private:
    std::multiset<int, std::greater<>> scores;
    std::unordered_map<int, std::multiset<int, int>::iterator> player_id_to_entry;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */