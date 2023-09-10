// https://leetcode.com/problems/count-the-number-of-good-subarrays/description/

class Solution
{
public:
    long long countGood(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> freq;

        auto cnt = 0;
        auto res = 0LL;

        for (auto left = 0, right = 0; right < std::size(nums); right++)
        {
            if (auto it = freq.find(nums[right]); it != std::end(freq))
            {
                cnt += it->second;
                it->second++;
            }
            else
            {
                freq.insert({ nums[right], 1 });
            }

            while (left < right)
            {
                if (auto it = freq.find(nums[left]); it != std::end(freq))
                {
                    const auto val = it->second - 1;

                    if (cnt - val >= k)
                    {
                        cnt -= val;                        
                        it->second--;
                        left++;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            if (cnt >= k)
            {
                res += left + 1;
            }
        }

        return res;
    }
};