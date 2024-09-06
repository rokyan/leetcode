// https://leetcode.com/problems/minimum-length-of-anagram-concatenation/description/

class Solution
{
public:
    int minAnagramLength(const std::string& s)
    {
        const auto n = std::size(s);

        std::vector<int> div;

        for (auto i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                div.push_back(i);
                div.push_back(n / i);
            }
        }

        std::sort(std::begin(div), std::end(div));

        for (auto d : div)
        {
            if (check(s, d))
            {
                return d;
            }
        }

        return -1;
    }

private:
    bool check(const std::string& s, std::size_t len)
    {
        std::array<int, 26> freq{ 0 };

        for (auto i = 0; i < len; i++)
        {
            freq[s[i] - 'a']++;
        }

        for (auto i = len; i < std::size(s); i += len)
        {
            std::array<int, 26> cur_freq{ 0 };

            for (auto j = i; j < i + len; j++)
            {
                cur_freq[s[j] - 'a']++;
            }

            if (!std::equal(std::cbegin(freq), std::cend(freq),
                std::cbegin(cur_freq), std::cend(cur_freq)))
            {
                return false;
            }
        }

        return true;
    }
};