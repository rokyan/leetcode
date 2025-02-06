// https://leetcode.com/problems/n-queens-ii/description/

class Solution
{
public:
    int totalNQueens(int n)
    {
        std::vector<char> used_cols(n);
        std::unordered_set<int> diag, anti_diag;

        return solve(1, n, used_cols, diag, anti_diag);
    }

private:
    int solve(int row, int n, std::vector<char>& used_cols,
        std::unordered_set<int>& diag, std::unordered_set<int>& anti_diag)
    {
        if (row == n + 1)
        {
            return 1;
        }
        else
        {
            auto res = 0;

            for (auto col = 1; col <= n; col++)
            {
                if (!used_cols[col - 1])
                {
                    const auto d = row - col;
                    const auto ad = row + col;

                    if (!diag.count(d) && !anti_diag.count(ad))
                    {
                        used_cols[col - 1] = true;
                        diag.insert(d);
                        anti_diag.insert(ad);
                        res += solve(row + 1, n, used_cols, diag, anti_diag);
                        anti_diag.erase(ad);
                        diag.erase(d);
                        used_cols[col - 1] = false;
                    }
                }
            }

            return res;
        }
    }
};