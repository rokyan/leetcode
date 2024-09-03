// https://leetcode.com/problems/hash-divided-string/description/

class Solution
{
public:
    std::string stringHash(const std::string& s, int k)
    {
        auto hash = std::string{};
        hash.reserve(std::size(s) / k);

        for (auto i = 0; i < std::size(s); i += k)
        {
            auto sum = 0;

            for (auto j = i; j < i + k; j++)
            {
                sum += s[j] - 'a';
            }

            hash.push_back('a' + sum % 26);
        }

        return hash;
    }
};