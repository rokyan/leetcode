// https://leetcode.com/problems/make-number-of-distinct-characters-equal/description/

class Solution
{
public:
    bool isItPossible(std::string word1, std::string word2)
    {
        std::array<int, 26> cnt1{};
        std::array<int, 26> cnt2{};

        auto d1 = 0;
        auto d2 = 0;

        for (auto c : word1)
        {
            if (cnt1[c - 'a']++ == 0)
            {
                d1++;
            }
        }

        for (auto c : word2)
        {
            if (cnt2[c - 'a']++ == 0)
            {
                d2++;
            }
        }

        for (auto c1 = 0; c1 < 26; c1++)
        {
            for (auto c2 = 0; c2 < 26; c2++)
            {
                if (cnt1[c1] > 0 && cnt2[c2] > 0)
                {
                    if (cnt1[c1]-- == 1)
                    {
                        d1--;
                    }

                    if (cnt1[c2]++ == 0)
                    {
                        d1++;
                    }

                    if (cnt2[c2]-- == 1)
                    {
                        d2--;
                    }

                    if (cnt2[c1]++ == 0)
                    {
                        d2++;
                    }

                    if (d1 == d2)
                    {
                        return true;
                    }

                    if (cnt1[c2]-- == 1)
                    {
                        d1--;
                    }

                    if (cnt1[c1]++ == 0)
                    {
                        d1++;
                    }

                    if (cnt2[c1]-- == 1)
                    {
                        d2--;
                    }

                    if (cnt2[c2]++ == 0)
                    {
                        d2++;
                    }
                }
            }
        }

        return false;
    }
};