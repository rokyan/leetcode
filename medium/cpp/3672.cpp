// https://leetcode.com/problems/sum-of-weighted-modes-in-subarrays/description/

class Solution
{
public:
    long long modeWeight(const std::vector<int>& nums, int k)
    {
        const int n = nums.size();

        std::unordered_map<int, int> freq;

        auto comp = [](const std::pair<int, int>& lhs, const std::pair<int, int>& rhs)
        {
            return lhs.first > rhs.first || lhs.first == rhs.first && lhs.second < rhs.second;
        };

        std::set<pair<int, int>, decltype(comp)> ordered;

        long long res = 0;

        for (int i = 0; i < n; i++)
        {
            ordered.erase({freq[nums[i]], nums[i]});
            freq[nums[i]]++;
            ordered.emplace(freq[nums[i]], nums[i]);

            if (i >= k)
            {
                ordered.erase({freq[nums[i - k]], nums[i - k]});
                freq[nums[i - k]]--;

                if (freq[nums[i - k]] > 0)
                {
                    ordered.emplace(freq[nums[i - k]], nums[i - k]);
                }
                
            }

            if (i >= k - 1)
            {
                const auto [f, mode] = *ordered.cbegin();
                res += 1LL * f * mode;
            }
        }

        return res;
    }
};