// https://leetcode.com/problems/maximum-palindromes-after-operations/description/

class Solution
{
public:
    int maxPalindromesAfterOperations(const std::vector<std::string>& words)
    {
        std::array<int, 26> freq{ 0 };
        std::vector<int> lens;
        lens.reserve(std::size(words));

        for (const auto& word : words)
        {
            for (auto c : word)
            {
                freq[c - 'a']++;
            }

            lens.push_back(std::size(word));
        }

        auto res = 0;

        std::sort(std::begin(lens), std::end(lens));

        for (auto len : lens)
        {
            auto cur = len - len % 2;

            for (auto i = 0; i < 26 && cur; i++)
            {
                auto t = std::min(cur, freq[i] / 2 * 2);
                freq[i] -= t;
                cur -= t;
            }

            if (cur == 0)
            {
                res++;
            }
        }

        return res;
    }
};