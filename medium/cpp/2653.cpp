// https://leetcode.com/problems/sliding-subarray-beauty/description/

class Solution
{
public:
    std::vector<int> getSubarrayBeauty(std::vector<int>& nums, int k, int x)
    {
        std::multiset<int> minset;
        std::multiset<int, std::greater<>> maxset;

        for (auto i = 0; i < k; i++)
        {
            if (nums[i] < 0)
            {
                maxset.insert(nums[i]);
            }

            if (std::size(maxset) > x)
            {
                const auto val = *std::begin(maxset);
                maxset.erase(std::begin(maxset));
                minset.insert(val);
            }
        }

        std::vector<int> res;
        res.reserve(std::size(nums));

        res.push_back(std::size(maxset) == x ? *std::begin(maxset) : 0);

        for (auto i = k; i < std::size(nums); i++)
        {
            if (nums[i] < 0)
            {
                maxset.insert(nums[i]);
            }

            if (std::size(maxset) > x)
            {
                const auto val = *std::begin(maxset);
                maxset.erase(std::begin(maxset));
                minset.insert(val);
            }

            if (nums[i - k] < 0)
            {
                if (const auto it = maxset.find(nums[i - k]); it != std::end(maxset))
                {
                    maxset.erase(it);
                    
                    if (std::size(minset) > 0)
                    {
                        maxset.insert(*std::begin(minset));
                        minset.erase(std::begin(minset));
                    }
                }
                else
                {
                    minset.erase(minset.find(nums[i - k]));
                }
            }

            res.push_back(std::size(maxset) == x ? *std::begin(maxset) : 0);
        }

        return res;
    }
};