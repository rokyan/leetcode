// https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/

class Solution
{
public:
    std::vector<int> smallestTrimmedNumbers(std::vector<std::string>& nums, std::vector<std::vector<int>>& queries)
    {
        const auto queries_count = std::size(queries);
        const auto nums_count = std::size(nums);

        std::vector<int> res(queries_count);

        for (auto q_idx = 0; q_idx < queries_count; q_idx++)
        {
            std::vector<std::pair<std::string, int>> data(nums_count);

            for (auto n_idx = 0; n_idx < nums_count; n_idx++)
            {
                data[n_idx] = { nums[n_idx].substr(std::size(nums[n_idx]) - queries[q_idx][1]), n_idx };
            }

            std::nth_element(std::begin(data), std::begin(data) + queries[q_idx][0] - 1, std::end(data));

            res[q_idx] = data[queries[q_idx][0] - 1].second;
        }

        return res;
    }
};