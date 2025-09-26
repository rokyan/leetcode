// https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/

class Solution
{
public:
    std::vector<int> fullBloomFlowers(
        const std::vector<std::vector<int>>& flowers,
        const std::vector<int>& people)
    {
        std::map<int, int> flowersInBloom;

        for (const auto& flower : flowers)
        {
            flowersInBloom[flower[0]]++;
            flowersInBloom[flower[1] + 1]--;
        }

        std::vector<std::pair<int, int>> peopleWithIdx(std::size(people));

        for (auto idx = 0; idx < std::size(people); idx++)
        {
            peopleWithIdx[idx] = {people[idx], idx};
        }

        std::ranges::sort(peopleWithIdx);

        std::vector<int> res(std::size(peopleWithIdx));

        auto it = std::cbegin(flowersInBloom);
        auto delta = 0;

        for (auto idx = 0; idx < std::size(peopleWithIdx); idx++)
        {
            while (it != std::cend(flowersInBloom) && it->first <= peopleWithIdx[idx].first)
            {
                delta += it->second;
                ++it;
            }

            res[peopleWithIdx[idx].second] = delta;
        }

        return res;
    }
};