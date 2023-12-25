// https://leetcode.com/problems/count-beautiful-substrings-i/description/

class Solution
{
public:
    int beautifulSubstrings(std::string s, int k)
    {
        const auto n = std::size(s);

        const auto vowels = std::string{"aeiou"};

        auto res = 0;

        for (auto i = 0, cnt = 0; i < n; i++)
        {
            for (auto j = i; j < n; j++)
            {
                if (vowels.find(s[j]) != std::string::npos)
                {
                    cnt++;
                }

                if (cnt == j - i + 1 - cnt && cnt * cnt % k == 0)
                {
                    res++;
                }
            }

            cnt = 0;
        }

        return res;
    }
};