// https://leetcode.com/problems/maximal-range-that-each-element-is-maximum-in-it/description/

class Solution
{
public:
    std::vector<int> maximumLengthOfRanges(std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> res(n);

        std::vector<int> st;
        st.push_back(0);

        for (auto i = 1; i < n; i++)
        {
            while (!st.empty() && nums[st.back()] < nums[i])
            {
                st.pop_back();
            }

            if (!st.empty())
            {
                res[i] = st.back() + 1;
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

            const auto left = res[i];
            const auto right = st.empty() ? n - 1 : st.back() - 1;

            res[i] = right - left + 1;
            
            st.push_back(i);
        }

        return res;
    }
};