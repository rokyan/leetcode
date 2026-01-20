// https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/description/

class Solution
{
private:
    static constexpr int mod = 1000'000'007;

public:
    std::vector<int> sumAndMultiply(const std::string& s,
        const std::vector<std::vector<int>>& queries)
    {
        const int m = s.size();

        std::vector<int> pos;
        pos.reserve(m);

        std::vector<int> val;
        val.reserve(m);

        for (int i = 0; i < m; i++)
        {
            if (s[i] != '0')
            {
                pos.push_back(i);
                val.push_back(s[i] - '0');
            }
        }

        const int n = pos.size();

        if (n == 0)
        {
            return std::vector<int>(queries.size());
        }

        std::vector<int> prefSum(n);
        prefSum[0] = val[0];

        for (int i = 1; i < n; i++)
        {
            prefSum[i] = val[i] + prefSum[i - 1];
            prefSum[i] %= mod;
        }

        std::vector<int> prefNum(n);
        prefNum[0] = val[0];

        for (int i = 1; i < n; i++)
        {
            prefNum[i] = val[i] + (i > 0 ? 1LL * prefNum[i - 1] * 10 % mod : 0);
            prefNum[i] %= mod;
        }

        std::vector<int> res;
        res.reserve(queries.size());

        for (const auto& query : queries)
        {
            const int l = query[0];
            const int r = query[1];

            const auto lit = std::lower_bound(pos.begin(), pos.end(), l);
            const int nl = std::distance(pos.begin(), lit);

            if (lit == pos.end() && nl > r)
            {
                res.push_back(0);
                continue;
            }

            const auto rit = std::upper_bound(pos.begin(), pos.end(), r);

            if (rit == pos.begin())
            {
                res.push_back(0);
                continue;
            }

            const int nr = std::distance(pos.begin(), std::prev(rit));

            const int sum = prefSum[nr] - (nl > 0 ? prefSum[nl - 1] : 0);
            int x = prefNum[nr];

            if (nl > 0)
            {
                x -= 1LL * prefNum[nl - 1] * pow(10, nr - nl + 1) % mod;
                x = (x + mod) % mod;
            }

            res.push_back(1LL * x * sum % mod);
        }

        return res;
    }

private:
    int pow(int x, int p)
    {
        if (p == 0)
        {
            return 1;
        }

        if (p & 1)
        {
            return 1LL * x * pow(x, p - 1) % mod;
        }

        const int temp = pow(x, p / 2);
        return 1LL * temp * temp % mod;
    }
};