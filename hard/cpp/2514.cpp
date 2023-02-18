class Solution
{
private:
    static constexpr auto mod = 1000 * 1000 * 1000 + 7;

public:
    int countAnagrams(std::string s)
    {
        const auto n = std::size(s);

        std::vector<int> f(n + 1);
        f[0] = 1;

        std::vector<int> inv(n + 1);

        for (auto i = 1; i <= n; i++)
        {
            f[i] = 1LL * f[i - 1] * i % mod;
            inv[i] = bin_pow(f[i], mod - 2);
        }

        std::string acc;

        auto res = 1;

        for (auto i = 0; i < n; i++)
        {
            if (s[i] == ' ')
            {
                auto cur = count(acc, f, inv);

                res = 1LL * res * cur % mod;

                acc.clear();
            }
            else
            {
                acc.push_back(s[i]);
            }
        }

        if (!acc.empty())
        {
            auto cur = count(acc, f, inv);

            res = 1LL * res * cur % mod;
        }

        return res;
    }

private:
    int bin_pow(int n, int pow)
    {
        if (pow == 1)
        {
            return n;
        }

        if (pow & 1)
        {
            return 1LL * n * bin_pow(n, pow - 1) % mod; 
        }

        const auto temp = bin_pow(n, pow >> 1);

        return 1LL * temp * temp % mod;
    }

    int count(const std::string& s, const std::vector<int>& f, const std::vector<int>& inv)
    {
        auto ret = f[std::size(s)];

        std::array<int, 26> cnt { 0 };

        for (auto j = 0; j < std::size(s); j++)
        {
            cnt[s[j] - 'a']++;
        }

        for (auto j = 0; j < 26; j++)
        {
            if (cnt[j] > 0)
            {
                ret = 1LL * ret * inv[cnt[j]] % mod;
            }
        }

        return ret;
    }
};