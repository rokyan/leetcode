class Solution
{
public:
    bool validPalindrome(const std::string& s)
    {
        if (s.empty())
        {
            return true;
        }

        auto first = 0;
        auto last = static_cast<int>(std::size(s)) - 1;

        while (first < last)
        {
            if (s[first] != s[last])
            {
                return isPalindrome(s, first + 1, last) ||
                    isPalindrome(s, first, last - 1);
            }
            else
            {
                first++;
                last--;
            }
        }

        return true;
    }

private:
    bool isPalindrome(const std::string& s, int first, int last)
    {
        while (first < last)
        {
            if (s[first] != s[last])
            {
                return false;
            }

            first++;
            last--;
        }

        return true;
    }
};