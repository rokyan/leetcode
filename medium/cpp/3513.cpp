// https://leetcode.com/problems/number-of-unique-xor-triplets-i/description/

class Solution
{
public:
    int uniqueXorTriplets(const std::vector<int>& nums)
    {
        const int n = std::size(nums);

        if (n <= 2)
        {
            return n;
        }

        int p = 1;

        while (p <= n)
        {
            p *= 2;
        }

        return p;
    }
};