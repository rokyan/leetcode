// https://leetcode.com/problems/word-squares-ii/description/

class Solution
{
public:
    std::vector<std::vector<std::string>> wordSquares(const std::vector<std::string>& words)
    {
        std::vector<char> taken(words.size());
        std::vector<std::string> taken_words;
        rec(0, taken, taken_words, words);
        std::ranges::sort(res);
        return res;
    }

private:
    void rec(int taken_count, std::vector<char>& taken,
        std::vector<std::string>& taken_words, const std::vector<std::string>& words)
    {
        if (taken_count == 4)
        {
            const std::string& top = taken_words[0];
            const std::string& left = taken_words[1];
            const std::string& right = taken_words[2];
            const std::string& bottom = taken_words[3];

            if (top[0] == left[0] && top[3] == right[0]
                && bottom[0] == left[3] && bottom[3] == right[3])
            {
                res.push_back(taken_words);
            }
        }
        else
        {
            for (int i = 0; i < words.size(); i++)
            {
                if (!taken[i])
                {
                    taken[i] = true;
                    taken_words.push_back(words[i]);
                    rec(taken_count + 1, taken, taken_words, words);
                    taken_words.pop_back();
                    taken[i] = false;
                }
            }
        }
    }

private:
    std::vector<std::vector<std::string>> res;
};