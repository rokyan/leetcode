// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

class Solution
{
public:
    int largestRectangleArea(const std::vector<int>& heights)
    {
        const auto n = static_cast<int>(std::size(heights));

        std::vector<int> st;

        std::vector<int> left(n, -1);
        std::vector<int> right(n, -1);

        for (auto i = 0; i < n; i++)
        {
            while (!st.empty() && heights[st.back()] >= heights[i])
            {
                right[st.back()] = i;
                st.pop_back();
            }

            if (!st.empty())
            {
                left[i] = st.back();
            }

            st.push_back(i);
        }

        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            const auto take_left = left[i] == -1 ? i + 1 : i - left[i];
            const auto take_right = right[i] == -1 ? n - i : right[i] - i;
            res = std::max(res, (take_left + take_right - 1) * heights[i]);
        }    

        return res;
    }
};