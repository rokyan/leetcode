// https://leetcode.com/problems/change-minimum-characters-to-satisfy-one-of-three-conditions/

class Solution
{
public:
    int minCharacters(std::string a, std::string b)
    {
        std::array<int, 26> freq_a{ 0 };

        for (auto c : a)
        {
            freq_a[c - 'a']++;
        }

        std::array<int, 26> freq_b{ 0 };

        for (auto c : b)
        {
            freq_b[c - 'a']++;
        }

        auto res = static_cast<int>(std::size(a) + std::size(b));

        for (auto c = 0; c < 26; c++)
        {
            if (c > 0)
            {
                auto cnt = 0;

                for (auto i = c; i < 26; i++)
                {
                    cnt += freq_a[i];
                }

                for (auto i = 0; i < c; i++)
                {
                    cnt += freq_b[i];
                }

                res = std::min(res, cnt);

                cnt = 0;

                for (auto i = c; i < 26; i++)
                {
                    cnt += freq_b[i];
                }

                for (auto i = 0; i < c; i++)
                {
                    cnt += freq_a[i];
                }

                res = std::min(res, cnt);
            }

            auto cnt = 0;

            for (auto i = 0; i < 26; i++)
            {
                if (i != c)
                {
                    cnt += freq_a[i] + freq_b[i];
                }
            }

            res = std::min(res, cnt);
        }

        return res;
    }
};