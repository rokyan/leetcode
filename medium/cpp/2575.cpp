// https://leetcode.com/problems/find-the-divisibility-array-of-a-string/description/

class Solution
{
public:
    std::vector<int> divisibilityArray(std::string word, int m)
    {
        const auto n = std::size(word);
        std::vector<int> res(n);

        auto acc = 0LL;

        for (auto i = 0; i < n; i++)
        {
            const auto d = word[i] - '0';

            acc = (10 * acc + d) % m;

            res[i] = acc == 0;
        }

        return res;
    }
};