class Solution
{
public:
    bool isSubsequence(const std::string& s, const std::string& t)
    {
        auto p = 0;

        for (auto i = 0; i < std::size(t) && p < std::size(s); i++)
        {
            if (t[i] == s[p])
            {
                p++;
            }
        }

        return p == std::size(s);
    }
};