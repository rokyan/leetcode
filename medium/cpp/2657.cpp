// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/

class Solution
{
public:
    std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B)
    {
        const auto n = std::size(A);

        std::vector<char> probeA(n + 1), probeB(n + 1);

        std::vector<int> res(n);

        for (auto i = 0; i < n; i++)
        {
            probeA[A[i]] = true;
            probeB[B[i]] = true;

            res[i] = probeA[B[i]] + probeB[A[i]];

            if (A[i] == B[i])
            {
                res[i]--;
            }

            if (i > 0)
            {
                res[i] += res[i - 1];
            }
        }

        return res;
    }
};