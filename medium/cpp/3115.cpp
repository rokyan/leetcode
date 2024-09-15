// https://leetcode.com/problems/maximum-prime-difference/description/

class Solution
{
public:
    int maximumPrimeDifference(const std::vector<int>& nums)
    {
        int l = 0;
        int r = std::size(nums) - 1;

        while (!is_prime(nums[l])) l++;
        while (!is_prime(nums[r])) r--;

        return r - l;
    }

private:
    bool is_prime(int x)
    {
        if (x <= 1)
        {
            return false;
        }

        for (auto i = 2; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                return false;
            }
        }

        return true;
    }
};