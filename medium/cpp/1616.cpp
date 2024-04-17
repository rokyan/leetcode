// https://leetcode.com/problems/split-two-strings-to-make-palindrome/description/

class Solution
{
public:
    bool checkPalindromeFormation(std::string a, std::string b)
    {
        return check(a, b) || check(b, a);
    }

private:
    static bool check(const std::string& a, const std::string& b)
    {
        const auto n = static_cast<int>(std::size(a));

        auto pref = 0;

        while (pref < n / 2 && a[pref] == b[n - pref - 1])
        {
            pref++;
        }

        if (2 * pref >= n)
        {
            return true;
        }

        auto first = true;
        auto second = true;

        for (auto i = pref, j = n - pref - 1; i <= j; i++, j--)
        {
            if (a[i] != a[j])
            {
                first = false;
            }

            if (b[i] != b[j])
            {
                second = false;
            }
        }

        return first || second;
    }
};