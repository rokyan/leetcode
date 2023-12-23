// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/

class Solution
{
public:
    std::vector<int> lexicographicallySmallestArray(std::vector<int>& nums, int limit)
    {
        const auto n = std::size(nums);

        std::vector<std::pair<int, int>> nwp;
        nwp.reserve(n);

        for (auto i = 0; i < n; i++)
        {
            nwp.emplace_back(nums[i], i);
        }

        std::sort(std::begin(nwp), std::end(nwp));

        std::vector<int> val;
        val.reserve(n);
        std::vector<int> pos;
        pos.reserve(n);

        std::vector<int> res(n);

        for (auto i = 0; i < n; i++)
        {
            if (val.empty() || val.back() + limit >= nwp[i].first)
            {
                val.push_back(nwp[i].first);
                pos.push_back(nwp[i].second);
            }
            else
            {
                std::sort(std::begin(val), std::end(val));
                std::sort(std::begin(pos), std::end(pos));

                for (auto j = 0; j < std::size(val); j++)
                {
                    res[pos[j]] = val[j];
                }

                val.clear();
                pos.clear();

                val.push_back(nwp[i].first);
                pos.push_back(nwp[i].second);
            }
        }

        std::sort(std::begin(val), std::end(val));
        std::sort(std::begin(pos), std::end(pos));

        for (auto j = 0; j < std::size(val); j++)
        {
            res[pos[j]] = val[j];
        }

        return res;
    }
};