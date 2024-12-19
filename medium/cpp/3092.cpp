// https://leetcode.com/problems/most-frequent-ids/description/

class Solution
{
public:
    std::vector<long long> mostFrequentIDs(const std::vector<int>& nums, const std::vector<int>& freq)
    {
        std::unordered_map<int, long long> cnt;
        std::multiset<long long, std::greater<>> cnts;
        std::vector<long long> res(std::size(nums));

        for (auto i = 0; i < std::size(nums); i++)
        {
            const auto prev = cnt[nums[i]];
            const auto cur = prev + freq[i];

            if (const auto it = cnts.find(prev); it != std::end(cnts))
            {
                cnts.erase(it);
            }

            cnts.insert(cur);
            cnt[nums[i]] = cur;
            res[i] = *std::cbegin(cnts);
        }

        return res;
    }
};