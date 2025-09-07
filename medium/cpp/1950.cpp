// https://leetcode.com/problems/maximum-of-minimum-values-in-all-subarrays/description/

class Solution
{
public:
    std::vector<int> findMaximums(const std::vector<int>& nums)
    {
        const int n = std::size(nums);

        std::vector<int> st;

        std::vector<std::pair<int, int>> ends(n, {0, n - 1});

        for (auto i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.back()] >= nums[i])
            {
                ends[st.back()].second = i - 1;
                st.pop_back();
            }

            if (!st.empty())
            {
                ends[i].first = st.back() + 1;
            }

            st.push_back(i);
        }

        std::vector<std::pair<int, int>> v;
        v.reserve(n);

        for (auto i = 0; i < n; i++)
        {
            const auto& e = ends[i];
            v.emplace_back(nums[i], e.second - e.first + 1);
        }

        std::ranges::sort(v, std::greater<>{});

        auto lastLen = 1;

        std::vector<int> res(n);

        for (const auto& e : v)
        {
            while (lastLen <= e.second)
            {
                res[lastLen - 1] = e.first;
                lastLen++;
            }
        }

        return res;
    }
};