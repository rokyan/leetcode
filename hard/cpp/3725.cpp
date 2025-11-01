// https://leetcode.com/problems/count-ways-to-choose-coprime-integers-from-rows/description/

class Solution
{
private:
    static constexpr int mod = 1000'000'000 + 7;

public:
    int countCoprime(const std::vector<std::vector<int>>& mat)
    {
        const int n = std::size(mat);
        const int m = std::size(mat.front());

        std::unordered_map<int, int> cnt;
        std::unordered_map<int, int> next;

        for (int j = 0; j < m; j++)
        {
            cnt[mat[0][j]]++;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                for (const auto [key, value] : cnt)
                {
                    const int g = gcd(key, mat[i][j]);
                    next[g] += value;
                    next[g] %= mod;
                }
            }

            std::swap(cnt, next);
            next.clear();
        }

        return cnt[1];
    }

private:
    int gcd(int x, int y)
    {
        if (x == 0)
        {
            return y;
        }

        return gcd(y % x, x);
    }
};