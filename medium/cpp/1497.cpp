// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/

class Solution
{
public:
    bool canArrange(std::vector<int>& arr, int k)
    {
        std::vector<int> mod(k);

        for (auto e : arr)
        {
            mod[(e % k + k) % k]++;
        }

        if (mod[0] % 2 == 1)
        {
            return false;
        }

        for (auto i = 1; i < k / 2 + k % 2; i++)
        {
            if (mod[i] != mod[k - i])
            {
                return false;
            }
        }

        if (k % 2 == 0 && mod[k / 2] % 2 == 1)
        {
            return false;
        }

        return true;
    }
};