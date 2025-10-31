// https://leetcode.com/problems/lexicographically-smallest-string-after-reverse/description/

class Solution
{
public:
    std::string lexSmallest(std::string& s)
    {
        const int n = std::size(s);
        std::string res{s};

        for (int take = 1; take <= n; take++)
        {
            if (s[take - 1] > res.front())
            {
                continue;
            }

            std::reverse(std::begin(s), std::next(std::begin(s), take));
            res = std::min(res, s);
            std::reverse(std::begin(s), std::next(std::begin(s), take));
        }

        for (int take = 1; take <= n; take++)
        {
            const int start = n - take;
            std::reverse(std::next(std::begin(s), start), std::end(s));
            res = std::min(res, s);
            std::reverse(std::next(std::begin(s), start), std::end(s));
        }

        return res;
    }
};