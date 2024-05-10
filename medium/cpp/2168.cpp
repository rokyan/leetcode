// https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency/description/

class Solution
{
public:
    int equalDigitFrequency(std::string s)
    {
        const auto n = std::size(s);

        std::unordered_set<unsigned long long> un;

        std::vector<unsigned long long> h(n);
        std::vector<unsigned long long> pow(n);

        auto p = 1ULL;

        for (auto i = 0; i < n; i++, p *= 31)
        {
            pow[i] = p;
            h[i] = (s[i] - '0' + 1) * pow[i] + (i > 0 ? h[i - 1] : 0);
        }

        std::vector<std::vector<int>> pref(n, std::vector<int>(10));

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            if (i > 0)
            {
                pref[i] = pref[i - 1];
            }

            pref[i][s[i] - '0']++;

            for (auto j = 0; j <= i; j++)
            {
                auto d = -1;
                auto pass = true;

                for (auto c = 0; c <= 9 && pass; c++)
                {
                    const auto t = pref[i][c] - (j > 0 ? pref[j - 1][c] : 0);

                    if (t)
                    {
                        if (d == -1)
                        {
                            d = t;
                        }
                        else
                        {
                            pass = d == t;
                        }
                    }
                }

                if (pass)
                {
                    auto hv = h[i] - (j > 0 ? h[j - 1] : 0);
                    hv *= pow[n - 1 - j];
                    un.insert(hv);
                }
            }
        }

        return std::size(un);
    }
};