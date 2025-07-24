// https://leetcode.com/problems/find-the-lexicographically-largest-string-from-the-box-i/description/

class Solution
{
public:
    std::string answerString(const std::string& word, int numFriends)
    {
        if (numFriends == 1)
        {
            return word;
        }

        const auto n = std::size(word);


        std::string_view sw{word};
        std::string_view res;

        const auto len = n - numFriends + 1;

        for (auto i = 0; i < n; i++)
        {
            const auto take = std::min(len, n - i);
            const auto cand = sw.substr(i, take);

            if (cand > res)
            {
                res = cand;
            }
        }

        return std::string{std::cbegin(res), std::cend(res)};
    }
};