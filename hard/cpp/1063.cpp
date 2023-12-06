// https://leetcode.com/problems/number-of-valid-subarrays/description/

class Solution
{
public:
    int validSubarrays(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> st;

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.back()] > nums[i])
            {
                res += i - st.back();
                st.pop_back();
            }

            st.push_back(i);
        }

        for (auto i = 0; i < std::size(st); i++)
        {
            res += n - st[i];
        }

        return res;
    }
};