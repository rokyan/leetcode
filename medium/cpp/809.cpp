// https://leetcode.com/problems/expressive-words/description/

class Solution
{
public:
    int expressiveWords(std::string s, std::vector<std::string>& words)
    {
        auto res = 0;

        for (const auto& word : words)
        {
            auto matched = true;
            auto i = 0;
            auto j = 0;

            for (; matched && i < std::size(s) && j < std::size(word); )
            {
                if (s[i] != word[j])
                {
                    matched = false;
                    break;
                }

                auto ni = i;

                while (ni < std::size(s) && s[ni] == s[i])
                {
                    ni++;
                }

                auto nj = j;

                while (nj < std::size(word) && word[nj] == word[j])
                {
                    nj++;
                }

                if (nj - j == ni - i || ni - i >= nj - j && ni - i >= 3)
                {
                    i = ni;
                    j = nj;
                    continue;
                }

                matched = false;
            }

            matched = i == std::size(s) && j == std::size(word);

            if (matched)
            {
                res++;
            }
        }

        return res;
    }
};