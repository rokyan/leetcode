// https://leetcode.com/problems/reverse-words-in-a-string-ii/

class Solution
{
public:
    void reverseWords(std::vector<char>& s)
    {
        auto p = std::begin(s);

        while (p != std::end(s))
        {
            auto end = p;

            while (end != std::end(s) && *end != ' ')
            {
                ++end;
            }

            std::reverse(p, end);
            p = end;

            if (p != std::end(s))
            {
                ++p;
            }
        }

        std::reverse(std::begin(s), std::end(s));
    }
};