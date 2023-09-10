// https://leetcode.com/problems/word-break-ii/description/

class Solution
{
public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict)
    {
        const auto n = std::size(s);
        const auto m = std::size(wordDict);

        std::vector<std::vector<int>> ss(n);

        for (auto i = 0; i < n; i++)
        {
            for (auto j = 0; j < m; j++)
            {
                const auto len = std::size(wordDict[j]);

                if (i + len - 1 < n && std::string_view(s).substr(i, len) == wordDict[j])
                {
                    ss[i].push_back(j);
                }
            }
        }

        std::vector<std::string> res;

        solve(ss, 0, n, {}, wordDict, res);

        return res;
    }

private:
    void solve(const std::vector<std::vector<int>>& ss, int pos, int n, std::vector<int> acc,
        const std::vector<std::string>& words, std::vector<std::string>& res)
    {
        if (pos == n)
        {
            res.push_back(words[acc.front()]);

            for (auto i = 1; i < std::size(acc); i++)
            {
                res.back() += " " + words[acc[i]];
            }

            return;
        }

        for (auto idx : ss[pos])
        {
            acc.push_back(idx);
            solve(ss, pos + std::size(words[idx]), n, acc, words, res);
            acc.pop_back();
        }
    }
};