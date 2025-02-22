class Solution
{
public:
    std::string mergeAlternately(const std::string& word1, const std::string& word2)
    {
        const auto n = std::size(word1);
        const auto m = std::size(word2);

        std::string res;
        res.reserve(n + m);

        for (auto i = 0; i < std::max(n, m); i++)
        {
            if (i < n)
            {
                res.push_back(word1[i]);
            }

            if (i < m)
            {
                res.push_back(word2[i]);
            }
        }

        return res;
    }
};