// https://leetcode.com/problems/make-the-prefix-sum-non-negative/

class Solution
{
public:
    int makePrefSumNonNegative(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        auto res = 0;
        auto s = 0LL;

        std::priority_queue<int> heap;

        for (auto i = 0; i < n; i++)
        {
            s += nums[i];
            heap.push(-nums[i]);

            while (s < 0)
            {
                res++;

                s -= -heap.top();
                heap.pop();
            }
        }

        return res;
    }
};