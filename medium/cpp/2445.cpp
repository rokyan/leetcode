// https://leetcode.com/problems/number-of-nodes-with-value-one/description/

class Solution
{
public:
    int numberOfNodes(int n, std::vector<int>& queries)
    {
        std::vector<char> marks(n + 1);

        for (auto q : queries)
        {
            marks[q] ^= true;
        }

        return count(1, n, marks);
    }

private:
    int count(int v, int n, const std::vector<char>& marks, bool acc = false)
    {
        if (v > n)
        {
            return 0;
        }

        acc ^= marks[v];
        return acc + count(v * 2, n, marks, acc) + count(v * 2 + 1, n, marks, acc);
    }
};