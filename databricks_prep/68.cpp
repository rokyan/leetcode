class Solution
{
public:
    std::vector<std::string> fullJustify(
        const std::vector<std::string>& words,
        int maxWidth)
    {
        std::vector<std::string> res;

        const auto n = std::size(words);

        for (auto i = 0; i < n; )
        {
            auto curLen = 0;
            auto j = i;

            while (j < n && curLen < maxWidth)
            {
                const auto newLen = curLen + std::size(words[j]) + (curLen > 0);

                if (newLen <= maxWidth)
                {
                    curLen = newLen;
                    j++;
                }
                else
                {
                    break;
                }
            }

            const auto wordsCount = j - i;

            if (wordsCount == 1)
            {
                res.push_back(words[i] + std::string(maxWidth - std::size(words[i]), ' '));
            }
            else if (j == n)
            {
                auto rem = maxWidth;

                res.push_back(words[i]);
                rem -= std::size(words[i]);

                for (auto k = i + 1; k < n; k++)
                {
                    res.back() += " " + words[k];
                    rem -= 1 + std::size(words[k]);
                }

                res.back() += std::string(rem, ' ');
            }
            else
            {
                auto rem = maxWidth;

                for (auto k = i; k < j; k++)
                {
                    rem -= std::size(words[k]);
                }

                const auto base = rem / (wordsCount - 1);
                auto add = rem % (wordsCount - 1);

                res.push_back(words[i]);

                for (auto k = i + 1; k < j; k++)
                {
                    res.back() += std::string(base + (add > 0), ' ');

                    if (add > 0)
                    {
                        add--;
                    }

                    res.back() += words[k];
                }
            }

            i = j;
        }

        return res;
    }
};