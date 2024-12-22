// https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-i/description/

class Solution
{
public:
    int minimumTimeToInitialState(const std::string& word, int k)
    {
        const auto n = std::size(word);

        auto cnt = 1;

        for (auto i = k; i < n; i += k)
        {
            auto j = i;

            while (j < n && word[j - i] == word[j])
            {
                j++;
            }

            if (j == n)
            {
                return cnt;
            }

            cnt++;
        }

        return cnt;
    }
};