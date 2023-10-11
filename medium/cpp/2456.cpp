// https://leetcode.com/problems/most-popular-video-creator/description/

class Solution
{
public:
    std::vector<std::vector<std::string>> mostPopularCreator(std::vector<std::string>& creators,
        std::vector<std::string>& ids, std::vector<int>& views)
    {
        std::unordered_map<std::string, std::vector<std::pair<std::string, int>>> by_creator;
        std::unordered_map<std::string, long long> cnt;
        auto max_cnt = 0LL;

        for (auto i = 0; i < std::size(creators); i++)
        {
            by_creator[creators[i]].push_back({ ids[i], views[i] });
            cnt[creators[i]] += views[i];
            max_cnt = std::max(max_cnt, cnt[creators[i]]);
        }

        std::vector<std::vector<std::string>> res;

        for (auto&& e : by_creator)
        {
            if (cnt[e.first] == max_cnt)
            {
                const auto em = *std::min_element(std::begin(e.second), std::end(e.second), [](const auto& lhs, const auto& rhs) {
                    return lhs.second > rhs.second || lhs.second == rhs.second && lhs.first < rhs.first;
                });

                res.push_back({ e.first, em.first });
            }
        }

        return res;
    }
};