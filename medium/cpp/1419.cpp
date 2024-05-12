// https://leetcode.com/problems/minimum-number-of-frogs-croaking/description/

class Solution
{
public:
    int minNumberOfFrogs(std::string croakOfFrogs)
    {
        std::array<int, 4> cnt{ 0 };

        std::unordered_map<char, int> codes
        {
            { 'c', 0 },
            { 'r', 1 },
            { 'o', 2 },
            { 'a', 3 },
            { 'k', 4 },
        };

        auto res = 0;
        auto frogs = 0;

        for (auto c : croakOfFrogs)
        {
            const auto code = codes[c];

            if (code == 0)
            {
                cnt[0]++;
                frogs++;
                res = std::max(res, frogs);
            }
            else
            {
                const auto prev = code - 1;

                if (cnt[prev] == 0)
                {
                    return -1;
                }

                cnt[prev]--;

                if (code != 4)
                {
                    cnt[code]++;
                }
                else
                {
                    frogs--;
                }
            }
        }

        if (std::any_of(std::cbegin(cnt), std::cend(cnt), [](int x) { return x > 0; }))
        {
            return -1;
        }

        return res;
    }
};