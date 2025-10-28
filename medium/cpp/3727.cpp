// https://leetcode.com/problems/maximum-alternating-sum-of-squares/description/

class Solution
{
public:
    long long maxAlternatingSum(std::vector<int>& nums)
    {
        const int n = std::size(nums);

        int l = 0;
        int r = n - 1;
        long long res = 0;
        bool takeMax = true;

        std::ranges::sort(nums, [](int e1, int e2) {
            return std::abs(e1) > std::abs(e2);
        });

        for (int take = 0; take < n; take++)
        {
            if (takeMax)
            {
                res += sq(nums[l++]);
            }
            else
            {
                res -= sq(nums[r--]);
            }

            takeMax ^= true;
        }

        return res;
    }

private:
    int sq(int x)
    {
        return x * x;
    }
};