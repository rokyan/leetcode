https://leetcode.com/problems/n-queens/description/

class Solution
{
public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> res;
        std::vector<std::string> sol(n, std::string(n, '.'));
        std::vector<char> used_cols(n);
        std::unordered_set<int> diag, anti_diag;

        solve(1, n, sol, used_cols, diag, anti_diag, res);

        return res;
    }

private:
    void solve(int row, int n, std::vector<string>& sol,
        std::vector<char>& used_cols, std::unordered_set<int>& diag, std::unordered_set<int>& anti_diag,
        std::vector<std::vector<std::string>>& res)
    {
        if (row == n + 1)
        {
            res.push_back(sol);
        }
        else
        {
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
                        sol[row - 1][col - 1] = 'Q';
                        solve(row + 1, n, sol, used_cols, diag, anti_diag, res);
                        sol[row - 1][col - 1] = '.';
                        anti_diag.erase(ad);
                        diag.erase(d);
                        used_cols[col - 1] = false;
                    }
                }
            }
        }
    }
};