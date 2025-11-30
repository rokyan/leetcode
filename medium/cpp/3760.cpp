// https://leetcode.com/problems/maximum-substrings-with-distinct-start/description/

class Solution
{
public:
    int maxDistinct(const std::string& s)
    {
        std::array<bool, 26> seen;
        seen.fill(0);

        int res = 0;

        for (auto c : s)
        {
            const int code = c - 'a';

            if (!seen[code])
            {
                seen[code] = true;
                res++;
            }
        }

        return res;
    }
};