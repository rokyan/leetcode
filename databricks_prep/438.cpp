class Solution
{
public:
    std::vector<int> findAnagrams(const std::string& s, const std::string& p)
    {
        const int n = std::size(s);

        std::array<int, 26> cnt;
        cnt.fill(0);

        int balance = 0;

        for (auto c : p)
        {
            if (cnt[c - 'a']++ == 0)
            {
                balance++;
            }
        }

        std::vector<int> res;
        res.reserve(n);

        for (int i = 0; i < n; i++)
        {
            if (cnt[s[i] - 'a']-- == 1)
            {
                balance--;
            }

            if (i >= std::size(p))
            {
                if (cnt[s[i - std::size(p)] - 'a']++ == 0)
                {
                    balance++;
                }
            }

            if (balance == 0)
            {
                res.push_back(i - std::size(p) + 1);
            }
        }

        return res;
    }
};