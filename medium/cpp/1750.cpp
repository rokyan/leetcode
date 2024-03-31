// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/

class Solution
{
public:
    int minimumLength(std::string s)
    {
        auto start = 0;
        auto end = static_cast<int>(std::size(s)) - 1;

        while (start < end)
        {
            if (s[start] != s[end])
            {
                return end - start + 1;
            }

            auto nstart = start;

            while (nstart <= end && s[nstart] == s[start])
            {
                nstart++;
            }

            auto nend = end;

            while (nend > nstart && s[nend] == s[end])
            {
                nend--;
            }

            start = nstart;
            end = nend;
        }

        return end - start + 1;
    }
};