// https://leetcode.com/problems/construct-smallest-number-from-di-string/description/

class Solution
{
public:
    std::string smallestNumber(std::string pattern)
    {
        std::vector<bool> used(9);

        static_cast<void>(solve("", -1, used, pattern));
        return res;
    }

private:
    bool solve(std::string acc, int pos, std::vector<bool>& used, const std::string& pattern)
    {
        if (pos == std::size(pattern))
        {
            res = acc;
            return true;
        }

        for (char c = '1'; c <= '9'; c++)
        {
            if (used[c - '1'] || pos != -1 && (pattern[pos] == 'I' && c <= acc.back() || pattern[pos] == 'D' && c >= acc.back()))
            {
                continue;
            }

            used[c - '1'] = true;
            acc.push_back(c);

            if (solve(acc, pos + 1, used, pattern))
            {
                return true;
            }

            used[c - '1'] = false;
            acc.pop_back();
        }

        return false;
    }

private:
    std::string res;
};