// https://leetcode.com/problems/permutation-sequence/description/

class Solution
{
public:
    std::string getPermutation(int n, int k)
    {
        k--;

        std::vector<int> facts(n + 1);
        facts[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            facts[i] = i * facts[i - 1];
        }

        std::string res;
        res.reserve(n);

        std::vector<char> used(n);

        for (int pos = 0; pos < n; pos++)
        {
            int rem = n - 1 - pos;
            int cont = facts[rem];
            int d = 1;

            while (cont <= k)
            {
                k -= cont;
                d++;
            }

            for (int i = 0; i < n; i++)
            {
                if (!used[i])
                {
                    d--;

                    if (d == 0)
                    {
                        used[i] = true;
                        res.push_back('0' + i + 1);
                        break;
                    }
                }
            }
        }

        return res;
    }
};