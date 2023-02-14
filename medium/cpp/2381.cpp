// https://leetcode.com/problems/shifting-letters-ii/description/

class Solution
{
public:
    std::string shiftingLetters(std::string s, std::vector<std::vector<int>>& shifts)
    {
        const auto n = std::size(s);

        std::vector<int> acc(n + 1);

        for (const auto& shift : shifts)
        {
            const auto left = shift[0];
            const auto right = shift[1];
            const auto dir = shift[2];

            if (dir == 1)
            {
                acc[left]++;
                acc[right + 1]--;
            }
            else
            {
                acc[left]--;
                acc[right + 1]++;
            }
        }

        for (auto i = 0, cur = 0; i < n; i++)
        {
            cur += acc[i];
            cur %= 26;

            if (cur < 0)
            {
                cur += 26;
            }

            s[i] = (s[i] - 'a' + cur) % 26 + 'a';
        }

        return s;
    }
};