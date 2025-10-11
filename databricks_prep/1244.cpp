class Leaderboard
{
public:
    Leaderboard() = default;
    
    void addScore(int playerId, int score)
    {
        if (const auto it = playerIdToScore.find(playerId); it != std::end(playerIdToScore))
        {
            scoreToPlayerId.erase({it->second, playerId});
            score += it->second;
        }

        scoreToPlayerId.emplace(score, playerId);
        playerIdToScore[playerId] = score;
    }
    
    int top(int K)
    {
        int total = 0;

        for (const auto [score, _] : scoreToPlayerId)
        {
            total += score;

            if (--K == 0)
            {
                break;
            }
        }

        return total;
    }
    
    void reset(int playerId)
    {
        if (const auto it = playerIdToScore.find(playerId); it != std::end(playerIdToScore))
        {
            scoreToPlayerId.erase({it->second, playerId});
        }

        playerIdToScore.erase(playerId);
    }

private:
    std::multiset<std::pair<int, int>, std::greater<>> scoreToPlayerId;
    std::unordered_map<int, int> playerIdToScore;
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */