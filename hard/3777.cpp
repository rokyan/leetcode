// https://leetcode.com/problems/minimum-deletions-to-make-alternating-substring/description/

class Solution
{
private:
    class SegmentTree final
    {
    public:
        SegmentTree(int size)
        : size{size}
        , tree(4 * size)
        {}

        int sum(int l, int r)
        {
            return sum(l, r, 1, 0, size - 1);
        }

        void update(int pos, int value)
        {
            update(pos, value, 1, 0, size - 1);
        }

    private:
        int sum(int l, int r, int v, int tl, int tr)
        {
            if (l == tl && r == tr)
            {
                return tree[v];
            }

            const int tm = (tl + tr) / 2;

            if (r <= tm)
            {
                return sum(l, r, v * 2, tl, tm);
            }

            if (l > tm)
            {
                return sum(l, r, v * 2 + 1, tm + 1, tr);
            }

            return sum(l, tm, v * 2, tl, tm) + sum(tm + 1, r, v * 2 + 1, tm + 1, tr);
        }

        void update(int pos, int value, int v, int tl, int tr)
        {
            if (tl == tr)
            {
                tree[v] = value;
                return;
            }

            const int tm = (tl + tr) / 2;

            if (pos <= tm)
            {
                update(pos, value, v * 2, tl, tm);
            }
            else
            {
                update(pos, value, v * 2 + 1, tm + 1, tr);
            }

            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }

    private:
        int size;
        std::vector<int> tree;
    };

public:
    std::vector<int> minDeletions(std::string& s,
        const std::vector<std::vector<int>>& queries)
    {
        const int n = s.size();

        SegmentTree tree{n - 1};

        for (int i = 0; i + 1 < n; i++)
        {
            tree.update(i, s[i] != s[i + 1]);
        }

        std::vector<int> res;
        res.reserve(queries.size());

        for (const auto& query : queries)
        {
            const int type = query[0];

            if (type == 1)
            {
                int pos = query[1];

                s[pos] = s[pos] == 'A' ? 'B' : 'A';

                if (pos > 0)
                {
                    tree.update(pos - 1, s[pos - 1] != s[pos]);
                }

                if (pos + 1 < n)
                {
                    tree.update(pos, s[pos] != s[pos + 1]);
                }
            }
            else // type 2
            {
                const int l = query[1];
                const int r = query[2];

                if (l == r)
                {
                    res.push_back(0);
                }
                else
                {
                    const int len = r - l + 1;
                    res.push_back(len - 1 - tree.sum(l, r - 1));
                }
            }
        }

        return res;
    }
};