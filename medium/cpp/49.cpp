// https://leetcode.com/problems/group-anagrams/description/

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> buckets;

        for (auto&& str : strs)
        {
            auto sorted = str;
            std::sort(std::begin(sorted), std::end(sorted));
            buckets[sorted].push_back(str);
        }

        std::vector<std::vector<std::string>> res(std::size(buckets));

        std::transform(std::begin(buckets), std::end(buckets), std::begin(res), [](auto&& entry) {
            return entry.second;
        });

        return res;
    }
};