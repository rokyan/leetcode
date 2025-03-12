class Solution
{
public:
    std::string longestPalindrome(const std::string& s)
    {
        std::string res;

        for (auto i = 0; i < std::size(s); i++)
        {
            if (const auto len = count(s, i, i); len > std::size(res))
            {
                res = s.substr(i - len / 2, len);
            }

            if (const auto len = count(s, i, i + 1); len > std::size(res))
            {
                res = s.substr(i - (len - 1) / 2, len);
            }
        }

        return res;
    }

private:
    int count(const std::string& s, int left, int right)
    {
        auto res = 0;

        while (left >= 0 && right < std::size(s) && s[left] == s[right])
        {
            res += (left == right ? 1 : 2);
            left--;
            right++;
        }

        return res;
    }
};