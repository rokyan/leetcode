// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/

class Solution
{
public:
    std::string findLexSmallestString(std::string s, int a, int b)
    {
        auto res = s;
        generate(s, a, b, res);
        return res;
    }

private:
    void generate(std::string s, int a, int b, std::string& res)
    {
        if (used.find(s) != std::end(used))
        {
            return;
        }

        res = std::min(res, s);
        used.insert(s);

        std::rotate(std::begin(s), std::next(std::begin(s), b), std::end(s));
        generate(s, a, b, res);

        for (auto i = 1; i < std::size(s); i += 2)
        {
            s[i] = (s[i] - '0' + a) % 10 + '0';
        }

        generate(s, a, b, res);
    }

private:
    std::unordered_set<std::string> used;
};