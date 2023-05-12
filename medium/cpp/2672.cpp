// https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/

class Solution
{
public:
    std::vector<int> colorTheArray(int n, std::vector<std::vector<int>>& queries)
    {
        const auto totq = std::size(queries);

        std::vector<int> res(totq);

        std::vector<int> color(n);

        for (auto qidx = 0, s = 0; qidx < totq; qidx++)
        {
            const auto idx = queries[qidx][0];
            const auto c = queries[qidx][1];

            if (idx > 0)
            {
                if (color[idx] == color[idx - 1] && color[idx - 1] > 0)
                {
                    s--;
                }

                if (c == color[idx - 1])
                {
                    s++;
                }
            }

            if (idx + 1 < n)
            {
                if (color[idx] == color[idx + 1] && color[idx + 1] > 0)
                {
                    s--;
                }

                if (c == color[idx + 1])
                {
                    s++;
                }
            }

            res[qidx] = s;
            color[idx] = c;
        }

        return res;
    }
};