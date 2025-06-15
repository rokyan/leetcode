// https://leetcode.com/problems/choose-k-elements-with-maximum-sum/description/

class Solution
{
public:
    std::vector<long long> findMaxSum(const std::vector<int>& nums1, const std::vector<int>& nums2, int k)
    {
        const auto n = std::size(nums1);

        std::vector<std::pair<int, int>> valsWithPos(n);

        for (auto i = 0; i < n; i++)
        {
            valsWithPos[i] = {nums1[i], i};
        }

        std::ranges::sort(valsWithPos);

        std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
        auto sum = 0LL;

        std::vector<long long> res(n);

        for (auto r = 0, l = 0; r < n; r++)
        {
            while (l < r && valsWithPos[l].first < valsWithPos[r].first)
            {
                heap.push(nums2[valsWithPos[l].second]);
                sum += nums2[valsWithPos[l].second];

                if (std::size(heap) > k)
                {
                    sum -= heap.top();
                    heap.pop();
                }

                l++;
            }

            res[valsWithPos[r].second] = sum;
        }

        return res;
    }
};