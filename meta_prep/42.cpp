class Solution
{
public:
    int trap(std::vector<int>& height)
    {
        std::vector<int> st;
        auto res = 0;

        const auto n = std::size(height);

        for (auto i = 0; i < n; i++)
        {
            if (height[i] == 0)
            {
                continue;
            }

            auto last = 0;

            while (!st.empty() && height[st.back()] < height[i])
            {
                res += (height[st.back()] - last) * (i - st.back() - 1);
                last = height[st.back()];
                st.pop_back();
            }

            if (!st.empty())
            {
                res += (height[i] - last) * (i - st.back() - 1);
            }

            st.push_back(i);
        }

        return res;
    }
};