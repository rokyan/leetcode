// https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/

class Solution
{
public:
    int maximumScore(std::vector<int>& nums, int k)
    {
        const auto n = static_cast<int>(std::size(nums));

        std::vector<int> st;
        st.reserve(n);

        std::vector<int> lo(n);

        for (auto i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.back()] >= nums[i])
            {
                st.pop_back();
            }

            lo[i] = st.empty() ? -1 : st.back();
            st.push_back(i);
        }

        st.clear();

        std::vector<int> hi(n);

        for (auto i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.back()] >= nums[i])
            {
                st.pop_back();
            }

            hi[i] = st.empty() ? n : st.back();
            st.push_back(i);
        }

        auto score = 0;

        for (auto i = 0; i < n; i++)
        {
            if (k > lo[i] && k < hi[i])
            {
                const auto cur = (hi[i] - lo[i] - 1) * nums[i];
                score = std::max(score, cur);
            }
        }

        return score;
    }
};