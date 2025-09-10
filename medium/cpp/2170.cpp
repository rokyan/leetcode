// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/description/

class Solution
{
public:
    int minimumOperations(vector<int>& nums)
    {
        const auto n = std::size(nums);

        if (n == 1)
        {
            return 0;
        }

        std::vector<std::unordered_map<int, int>> freq(2);

        for (auto i = 0; i < n; i++)
        {
            freq[i % 2][nums[i]]++;
        }

        if (std::size(freq[0]) == 1
            && std::size(freq[1]) == 1
            && nums[0] == nums[1])
        {
            return n / 2;
        }

        std::vector<std::vector<std::pair<int, int>>> mostFreq(2, std::vector<std::pair<int, int>>(2));

        for (auto f = 0; f < 2; f++)
        {
            for (const auto [key, value] : freq[f])
            {
                if (value > mostFreq[f][1].first)
                {
                    mostFreq[f][0] = mostFreq[f][1];
                    mostFreq[f][1] = {value, key};
                }
                else if (value > mostFreq[f][0].first)
                {
                    mostFreq[f][0] = {value, key};
                }
            }
        }

        if (mostFreq[0][1].second != mostFreq[1][1].second)
        {
            return n - mostFreq[0][1].first - mostFreq[1][1].first;
        }

        return n - std::max(mostFreq[0][0].first + mostFreq[1][1].first, mostFreq[0][1].first + mostFreq[1][0].first);
    }
};