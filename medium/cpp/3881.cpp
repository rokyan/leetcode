// https://leetcode.com/problems/direction-assignments-with-exactly-k-visible-people/description/

class Solution
{
private:
    static constexpr int mod = 1000'000'007;

public:
    int countVisiblePeople(int n, int pos, int k)
    {
        facts.resize(n + 1);
        facts[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            facts[i] = 1LL * facts[i - 1] * i % mod;
        }

        int res = 0;

        for (int left = 0; left <= k; left++)
        {
            const int right = k - left;
            const int rem = n - pos - 1;

            if (left <= pos && right <= rem)
            {
                res += 1LL * cnk(pos, left) * cnk(rem, right) % mod;
                res %= mod;
            }
        }

        return 2 * res % mod;
    }

private:
    int pow(int x, int p)
    {
        if (p == 0)
        {
            return 1;
        }

        if (p % 2)
        {
            return 1LL * x * pow(x, p - 1) % mod;
        }

        int half = pow(x, p / 2);
        return 1LL * half * half % mod;
    }

    int rev(int x)
    {
        return pow(x, mod - 2);
    }

    int cnk(int n, int k)
    {
        return 1LL * facts[n] * rev(facts[k]) % mod * rev(facts[n - k]) % mod;
    }

private:
    std::vector<int> facts;
};