// https://leetcode.com/problems/shortest-word-distance-ii/description/

class WordDistance
{
public:
    WordDistance(std::vector<std::string>& wordsDict)
    {
        for (auto i = 0; i < std::size(wordsDict); i++)
        {
            pos[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(std::string word1, std::string word2)
    {
        const auto& pos_for_word1 = pos[word1];
        const auto& pos_for_word2 = pos[word2];

        auto res = std::abs(pos_for_word1.front() - std::abs(pos_for_word2.front()));

        for (auto p1 = 0, p2 = 0; p1 < std::size(pos_for_word1) && res > 1; p1++)
        {
            while (p2 < std::size(pos_for_word2) && pos_for_word2[p2] < pos_for_word1[p1])
            {
                p2++;
            }

            if (p2 < std::size(pos_for_word2))
            {
                res = std::min(res, pos_for_word2[p2] - pos_for_word1[p1]);
            }

            if (p2 > 0)
            {
                res = std::min(res, pos_for_word1[p1] - pos_for_word2[p2 - 1]);
            }
        }

        return res;
    }

private:
    std::map<std::string, std::vector<int>> pos;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */