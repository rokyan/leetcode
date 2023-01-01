// https://leetcode.com/problems/palindrome-partitioning/description/

class Solution
{
public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        std::vector<std::string> acc;
        std::vector<std::vector<std::string>> res;

        solve(0, s, acc, res);

        return res;
    }

private:
    void solve(int pos, const std::string& s, std::vector<string>& acc, std::vector<std::vector<std::string>>& res)
    {
        const auto n = std::size(s);

        if (pos == n)
        {
            res.push_back(acc);
            return;
        }

        for (auto end = pos; end < n; end++)
        {
            const auto len = end - pos + 1;

            auto palindrome = true;

            for (auto i = 0; i * 2 < len; i++)
            {
                if (s[pos + i] != s[end - i])
                {
                    palindrome = false;
                    break;
                }
            }

            if (palindrome)
            {
                acc.push_back(s.substr(pos, len));
                solve(end + 1, s, acc, res);
                acc.pop_back();
            }
        }
    }
};