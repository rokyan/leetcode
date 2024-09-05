// https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/description/

class Solution
{
public:
    long long countCompleteDayPairs(const std::vector<int>& hours)
    {
        std::array<int, 24> freq{ 0 };
        auto res = 0LL;

        for (auto hour : hours)
        {
            res += freq[(24 - hour % 24) % 24];
            freq[hour % 24]++;
        }

        return res;
    }
};