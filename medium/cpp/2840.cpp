https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/description/

class Solution
{
public:
    bool checkStrings(std::string s1, std::string s2)
    {
        return transform(s1) == transform(s2);
    }

private:
    std::string transform(const std::string& s)
    {
        std::string pre;
        pre.reserve(std::size(s) / 2);

        for (auto i = 0; i < std::size(s); i += 2)
        {
            pre.push_back(s[i]);
        }

        std::sort(std::begin(pre), std::end(pre));

        std::string suf;
        suf.reserve(std::size(s) / 2);

        for (auto i = 1; i < std::size(s); i += 2)
        {
            suf.push_back(s[i]);
        }

        std::sort(std::begin(suf), std::end(suf));

        return pre + suf;
    }
};