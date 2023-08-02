// https://leetcode.com/problems/largest-element-in-an-array-after-merge-operations/description/

class Solution
{
public:
    long long maxArrayValue(std::vector<int>& nums)
    {
        std::vector<long long> st;

        long long res = 0;

        for (int pos = std::size(nums) - 1; pos >= 0; pos--)
        {
            if (st.empty() || st.back() < nums[pos])
            {
                st.push_back(nums[pos]);
            }
            else
            {
                st.back() += nums[pos];
            }

            res = std::max(res, st.back());
        }

        return res;
    }
};