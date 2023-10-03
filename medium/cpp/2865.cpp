// https://leetcode.com/problems/beautiful-towers-i/description/

class Solution
{
public:
    long long maximumSumOfHeights(std::vector<int>& maxHeights)
    {
        const auto n = std::size(maxHeights);

        std::vector<long long> pre(n);
        std::vector<int> st;

        for (auto i = 0; i < n; i++)
        {
            while (!st.empty() && maxHeights[st.back()] > maxHeights[i])
            {
                st.pop_back();
            }

            if (st.empty())
            {
                pre[i] = 1LL * (i + 1) * maxHeights[i];
            }
            else
            {
                pre[i] = pre[st.back()] + 1LL * (i - st.back()) * maxHeights[i];
            }

            st.push_back(i);

            // std::cout << pre[i] << " ";
        }

        std::vector<long long> suf(n);

        st.clear();

        for (auto i = static_cast<int>(n) - 1; i >= 0; i--)
        {
            while (!st.empty() && maxHeights[st.back()] > maxHeights[i])
            {
                st.pop_back();
            }

            if (st.empty())
            {
                suf[i] = 1LL * (n - i) * maxHeights[i];
            }
            else
            {
                suf[i] = suf[st.back()] + 1LL * (st.back() - i) * maxHeights[i];
            }

            st.push_back(i);

            // std::cout << suf[i] << " ";
        }

        auto res = 0LL;

        for (auto i = 0; i < n; i++)
        {
            res = std::max(res, pre[i] + suf[i] - maxHeights[i]);
        }

        return res;
    }
};