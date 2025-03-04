class Solution
{
public:
    bool checkSubarraySum(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        if (n < 2)
        {
            return false;
        }
        
        std::unordered_map<int, int> pref;
        pref[0] = -1;

        for (auto i = 0, sum = 0; i < n; i++)
        {
            sum = (sum + nums[i]) % k;

            if (const auto it = pref.find(sum); it != std::end(pref))
            {
                if (i - it->second > 1)
                {
                    return true;
                }
            }
            else
            {
                pref.emplace(sum, i);
            }
        }
        
        return false;
    }
};