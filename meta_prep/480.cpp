class Solution
{
public:
    std::vector<double> medianSlidingWindow(const std::vector<int>& nums, int k)
    {
        std::multiset<int> lo;
        std::multiset<int> hi;

        for (auto i = 0; i < k; i++)
        {
            lo.insert(nums[i]);
        }

        for (auto t = 0; t < k / 2; t++)
        {
            hi.insert(*std::rbegin(lo));
            lo.erase(std::prev(std::end(lo)));
        }

        std::vector<double> res;
        res.reserve(std::size(nums));

        res.push_back(k % 2 == 1
            ? *std::rbegin(lo)
            : (.0 + *std::rbegin(lo) + *std::begin(hi)) / 2.0);

        for (auto i = k; i < std::size(nums); i++)
        {
            lo.insert(nums[i]);
            hi.insert(*std::rbegin(lo));
            lo.erase(std::prev(std::end(lo)));

            if (nums[i - k] <= *std::rbegin(lo))
            {
                lo.erase(lo.find(nums[i - k]));
            }
            else
            {
                hi.erase(hi.find(nums[i - k]));
            }

            while (std::size(lo) > k - k / 2)
            {
                hi.insert(*std::rbegin(lo));
                lo.erase(std::prev(std::end(lo)));
            }

            while (std::size(hi) > k / 2)
            {
                lo.insert(*std::begin(hi));
                hi.erase(std::begin(hi));
            }

            res.push_back(k % 2 == 1
                ? *std::rbegin(lo)
                : (.0 + *std::rbegin(lo) + *std::begin(hi)) / 2.0);
        }

        return res;
    }
};