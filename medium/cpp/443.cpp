// https://leetcode.com/problems/string-compression/description/

class Solution
{
public:
    int compress(std::vector<char>& chars)
    {
        const auto n = std::size(chars);

        auto total = 0;

        for (auto i = 0, p = 0; i < n; )
        {
            auto j = i;

            while (j < n && chars[j] == chars[i])
            {
                j++;
            }

            chars[p++] = chars[i];
            total++;

            if (j > i + 1)
            {
                auto val = j - i;

                std::vector<char> buf;

                while (val > 0)
                {
                    total++;
                    buf.push_back('0' + val % 10);
                    val /= 10;
                }

                for (auto it = std::rbegin(buf); it != std::rend(buf); it++)
                {
                    chars[p++] = *it;
                }
            }

            i = j;
        }

        return total;
    }
};