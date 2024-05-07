// https://leetcode.com/problems/longest-common-subsequence-between-sorted-arrays/description/

class Solution
{
public:
    std::vector<int> longestCommonSubsequence(std::vector<std::vector<int>>& arrays)
    {
        const auto n = std::size(arrays);

        std::vector<int> pointers(n);
        std::vector<int> res;

        for (;;)
        {
            auto max_value = arrays[0][pointers[0]];

            for (auto i = 1; i < n; i++)
            {
                if (arrays[i][pointers[i]] > max_value)
                {
                    max_value = arrays[i][pointers[i]];
                }
            }

            auto cnt = 0;

            for (auto i = 0; i < n; i++)
            {
                while (pointers[i] < std::size(arrays[i]) && arrays[i][pointers[i]] < max_value)
                {
                    pointers[i]++;
                }

                if (pointers[i] == std::size(arrays[i]))
                {
                    return res;
                }

                if (arrays[i][pointers[i]] == max_value)
                {
                    cnt++;
                }
            }

            if (cnt == n)
            {
                res.push_back(max_value);

                for (auto i = 0; i < n; i++)
                {
                    if (++pointers[i] == std::size(arrays[i]))
                    {
                        return res;
                    }
                }
            }
        }

        return res;
    }
};