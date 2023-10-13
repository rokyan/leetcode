// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/

class Solution
{
public:
    int maxConsecutiveAnswers(std::string answerKey, int k)
    {
        return std::max(solve(answerKey, 'T', 'F', k), solve(answerKey, 'F', 'T', k));
    }

private:
    int solve(const std::string& key, char x, char y, int k)
    {
        auto res = 0;

        for (auto l = 0, r = 0, changes = 0; l < std::size(key); l++)
        {
            while (r < std::size(key) && (key[r] == x || key[r] == y && changes < k))
            {
                changes += key[r] == y;
                r++;
            }

            res = std::max(res, r - l);

            if (r == std::size(key))
            {
                break;
            }

            if (key[l] == y)
            {
                changes--;
            }
        }

        return res;
    }
};