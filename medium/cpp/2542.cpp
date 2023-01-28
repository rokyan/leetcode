// https://leetcode.com/problems/maximum-subsequence-score/description/

class Solution
{
public:
    long long maxScore(std::vector<int>& nums1, std::vector<int>& nums2, int k)
    {
        const auto n = std::size(nums1);

        std::vector<std::pair<int, int>> zipped(n);

        for (auto i = 0; i < n; i++)
        {
            zipped[i].first = nums2[i];
            zipped[i].second = nums1[i];
        }

        std::sort(std::begin(zipped), std::end(zipped), std::greater<>{});

        std::multiset<int> nums;
        auto sum = 0LL;

        for (auto i = 0; i < k; i++)
        {
            sum += zipped[i].second;
            nums.insert(zipped[i].second);
        }

        auto ans = 1LL * sum * zipped[k - 1].first;

        for (auto i = k; i < n; i++)
        {
            sum -= *std::begin(nums);
            nums.erase(std::begin(nums));

            sum += zipped[i].second;
            nums.insert(zipped[i].second);

            ans = std::max(ans, 1LL * sum * zipped[i].first);
        }

        return ans;
    }
};