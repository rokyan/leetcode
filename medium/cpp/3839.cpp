// https://leetcode.com/problems/number-of-prefix-connected-groups/description/

class Solution
{
public:
    int prefixConnected(const std::vector<std::string>& words, int k)
    {
        const int n = words.size();

        std::unordered_map<std::string, int> freq;

        for (const auto& word : words)
        {
            if (word.size() >= k)
            {
                freq[word.substr(0, k)]++;
            }
        }

        int res = 0;

        for (const auto& [word, cnt] : freq)
        {
            if (cnt >= 2)
            {
                res++;
            }
        }

        return res;
    }
};