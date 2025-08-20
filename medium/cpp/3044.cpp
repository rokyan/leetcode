// https://leetcode.com/problems/most-frequent-prime/description/

class Solution
{
private:
    static constexpr std::array<int, 8> drow{1, 1, 0, -1, -1, -1, 0, 1};
    static constexpr std::array<int, 8> dcol{0, -1, -1, -1, 0, 1, 1, 1};

public:
    int mostFrequentPrime(const std::vector<std::vector<int>>& mat)
    {
        const auto n = std::size(mat);
        const auto m = std::size(mat.front());

        for (auto row = 0; row < n; row++)
        {
            for (auto col = 0; col < m; col++)
            {
                for (auto d = 0; d < 8; d++)
                {
                    traverse(row, col, n, m, d, mat, 0);
                }
            }
        }

        if (freq.empty())
        {
            return -1;
        }

        auto res = std::cbegin(freq)->first;

        for (const auto& [value, count] : freq)
        {
            if (count > freq[res] || count == freq[res] && value > res)
            {
                res = value;
            }
        }

        return res;
    }

private:
    void traverse(int row, int col, int n, int m, int d,
        const std::vector<std::vector<int>>& mat, int acc)
    {
        acc = 10 * acc + mat[row][col];

        if (take(acc))
        {
            freq[acc]++;
        }

        const auto nrow = row + drow[d];
        const auto ncol = col + dcol[d];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
        {
            traverse(nrow, ncol, n, m, d, mat, acc);
        }
    }

    bool take(int x)
    {
        if (x <= 10)
        {
            return false;
        }

        for (auto div = 2; div * div <= x; div++)
        {
            if (x % div == 0)
            {
                return false;
            }
        }

        return true;
    }

private:
    std::unordered_map<int, int> freq;
};