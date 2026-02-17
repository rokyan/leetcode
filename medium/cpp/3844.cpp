// https://leetcode.com/problems/longest-almost-palindromic-substring/description/

class Solution
{
public:
    int almostPalindromic(const std::string& s)
    {
        const int n = s.size();
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            int l = i;
            int r = i + 1;
            int len = 0;

            while (l >= 0 && r < n && s[l] == s[r])
            {
                len += 2;
                l--;
                r++;
            }

            // 1
            if (l >= 0)
            {
                int add = 0;
                int ll = l - 1;
                int rr = r;

                while (ll >= 0 && rr < n && s[ll] == s[rr])
                {
                    add += 2;
                    ll--;
                    rr++;
                }

                res = std::max(res, len + add + 1);
            }

            // 2
            if (r < n)
            {
                int add = 0;
                int ll = l;
                int rr = r + 1;

                while (ll >= 0 && rr < n && s[ll] == s[rr])
                {
                    add += 2;
                    ll--;
                    rr++;
                }

                res = std::max(res, len + add + 1);
            }
        }

        for (int i = 0; i < n; i++)
        {
            int l = i - 1;
            int r = i + 1;
            int len = 0;

            while (l >= 0 && r < n && s[l] == s[r])
            {
                l--;
                r++;
                len += 2;
            }

            res = std::max(res, len);
            len++;

            // 1
            if (l >= 0)
            {
                int add = 0;
                int ll = l - 1;
                int rr = r;

                while (ll >= 0 && rr < n && s[ll] == s[rr])
                {
                    add += 2;
                    ll--;
                    rr++;
                }

                res = std::max(res, len + add + 1);
            }

            // 2
            if (r < n)
            {
                int add = 0;
                int ll = l;
                int rr = r + 1;

                while (ll >= 0 && rr < n && s[ll] == s[rr])
                {
                    add += 2;
                    ll--;
                    rr++;
                }

                res = std::max(res, len + add + 1);
            }
        }

        return res;
    }
};