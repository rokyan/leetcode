class Solution
{
public:
    bool checkInclusion(const std::string& s1, const std::string& s2)
    {
        const int n = std::size(s1);
        const int m = std::size(s2);

        if (n > m)
        {
            return false;
        }
        
        std::array<int, 26> cnt;
        cnt.fill(0);

        int balance = 0;

        for (int i = 0; i < n; i++)
        {
            if (cnt[s1[i] - 'a']++ == 0)
            {
                balance++;
            }
        }
        
        for (auto i = 0; i < m; i++)
        {
            if (cnt[s2[i] - 'a']-- == 1)
            {
                balance--;
            }

            if (i >= n)
            {
                if (cnt[s2[i - n] - 'a']++ == 0)
                {
                    balance++;
                }
            }

            if (balance == 0)
            {
                return true;
            }
        }

        return false;
    }
};