// https://leetcode.com/problems/longest-common-prefix-between-adjacent-strings-after-removals/description/

class Solution
{
public:
    std::vector<int> longestCommonPrefix(const std::vector<std::string>& words)
    {
        std::multiset<int> lcps;

        const auto n = std::size(words);

        for (auto i = 0; i + 1 < n; i++)
        {
            lcps.insert(calcLcpLen(words[i], words[i + 1]));
        }

        std::vector<int> res(std::size(words));

        for (auto i = 0; i < n; i++)
        {
            auto prev = -1;

            if (i > 0)
            {
                prev = calcLcpLen(words[i - 1], words[i]);
            }

            auto next = -1;

            if (i + 1 < n)
            {
                next = calcLcpLen(words[i + 1], words[i]);
            }

            if (prev != -1)
            {
                lcps.erase(lcps.find(prev));
            }

            if (next != -1)
            {
                lcps.erase(lcps.find(next));
            }

            res[i] = lcps.empty() ? 0 : *std::crbegin(lcps);

            if (i > 0 && i + 1 < n)
            {
                res[i] = std::max(res[i], calcLcpLen(words[i - 1], words[i + 1]));
            }

            if (prev != -1)
            {
                lcps.insert(prev);
            }

            if (next != -1)
            {
                lcps.insert(next);
            }
        }

        return res;
    }

private:
    int calcLcpLen(const std::string& w1, const std::string& w2)
    {
        const auto minLen = std::min(std::size(w1), std::size(w2));
        auto res = 0;

        for (auto i = 0; i < minLen; i++)
        {
            if (w1[i] != w2[i])
            {
                break;
            }

            res++;
        }

        return res;
    }
};