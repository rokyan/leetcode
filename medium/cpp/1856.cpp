// https://leetcode.com/problems/maximum-subarray-min-product/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int maxSumMinProduct(std::vector<int>& nums)
    {
        const auto n = static_cast<int>(std::size(nums));

        std::vector<int> st;

        std::vector<int> left(n, -1);

        for (auto i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.back()] >= nums[i])
            {
                st.pop_back();
            }

            if (!st.empty())
            {
                left[i] = st.back();
            }

            st.push_back(i);
        }

        st.clear();

        std::vector<int> right(n, n);

        for (auto i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.back()] >= nums[i])
            {
                st.pop_back();
            }

            if (!st.empty())
            {
                right[i] = st.back();
            }

            st.push_back(i);
        }

        std::vector<long long> pref(n + 1);

        for (auto i = 0; i < n; i++)
        {
            pref[i + 1] = pref[i] + nums[i];
        }

        auto res = 0LL;

        for (auto i = 0; i < n; i++)
        {
            const auto l = left[i] + 1;
            const auto r = right[i] - 1;
            const auto sum = pref[r + 1] - pref[l];

            res = std::max(res, 1LL * sum * nums[i]);
        }

        return res % mod;
    }
};