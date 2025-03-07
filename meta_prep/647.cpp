class Solution
{
public:
    int countSubstrings(const std::string& s)
    {
        const auto n = std::size(s);

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            res += count(s, i, i) + count(s, i, i + 1);
        }

        return res;
    }

private:
    int count(const std::string& s, int left, int right)
    {
        const auto n = std::size(s);
        auto res = 0;

        while (left >= 0 && right < n && s[left] == s[right])
        {
            res++;
            left--;
            right++;
        }

        return res;
    }
};