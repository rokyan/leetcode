// https://leetcode.com/problems/count-bowl-subarrays/description/

class Solution
{
public:
    long long bowlSubarrays(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> st;

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.back()] < nums[i])
            {
                st.pop_back();
            }

            if (!st.empty() && i - st.back() + 1 >= 3)
            {
                res++;
            }

            st.push_back(i);
        }

        st.clear();

        for (auto i = static_cast<int>(n) - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.back()] < nums[i])
            {
                st.pop_back();
            }

            if (!st.empty() && st.back() - i + 1 >= 3)
            {
                res++;
            }

            st.push_back(i);
        }

        return res;
    }
};