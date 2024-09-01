// https://leetcode.com/problems/better-compression-of-string/description/

class Solution
{
public:
    const::string betterCompression(const std::string& compressed)
    {
        std::array<int, 26> freq{ 0 };

        for (auto i = 0; i < std::size(compressed); )
        {
            auto c = compressed[i++];
            auto cnt = 0;

            while (i < std::size(compressed) && std::isdigit(compressed[i]))
            {
                cnt = 10 * cnt + compressed[i++] - '0';
            }

            freq[c - 'a'] += cnt;
        }

        auto res = std::string{};
        res.reserve(std::size(compressed));

        for (auto i = 0; i < 26; i++)
        {
            if (freq[i] > 0)
            {
                res.push_back('a' + i);
                res += std::to_string(freq[i]);
            }
        }

        return res;
    }
};