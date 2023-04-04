// https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/

class Solution
{
private:
    using pii = std::pair<int, int>;

public:
    long long findScore(std::vector<int>& nums)
    {
        std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;

        for (auto idx = 0; idx < std::size(nums); idx++)
        {
            pq.emplace(nums[idx], idx);
        }

        std::unordered_set<int> marked;

        auto res = 0LL;

        while (!pq.empty())
        {
            const auto entry = pq.top();
            pq.pop();

            if (const auto it = marked.find(entry.second); it != std::end(marked))
            {
                continue;
            }

            res += entry.first;

            marked.insert(entry.second - 1);
            marked.insert(entry.second + 1);
        }

        return res;   
    }
};