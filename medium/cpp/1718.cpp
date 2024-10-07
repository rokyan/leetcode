// https://leetcode.com/problems/construct-the-lexicographically-largest-valid-sequence/description/

class Solution
{
public:
    std::vector<int> constructDistancedSequence(int n)
    {
        std::vector<bool> used(n + 1);
        std::vector<int> cur(2 * n - 1, -1);

        std::vector<int> res;

        solve(n, cur, used, res);

        return res;
    }

private:
    bool solve(int n, std::vector<int>& cur, std::vector<bool>& used, std::vector<int>& res)
    {
        auto p = 0;

        while (p < 2 * n - 1 && cur[p] != -1)
        {
            p++;
        }

        if (p == 2 * n - 1)
        {
            res = cur;
            return true;
        }
        else
        {
            for (auto v = n; v >= 1; v--)
            {
                if (!used[v] && (v == 1 || p + v < 2 * n - 1 && cur[p + v] == -1))
                {
                    used[v] = true;

                    cur[p] = v;
                    if (v > 1)
                    {
                        cur[p + v] = v;
                    }

                    if (solve(n, cur, used, res))
                    {
                        return true;
                    }

                    if (v > 1)
                    {
                        cur[p + v] = -1;
                    }
                    cur[p] = -1;
                    used[v] = false;
                }
            }

            return false;
        }
    }
};