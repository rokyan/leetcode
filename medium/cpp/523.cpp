// https://leetcode.com/problems/continuous-subarray-sum/description/

class Solution
{
public:
    bool checkSubarraySum(std::vector<int>& nums, int k)
    {
        if (std::size(nums) < 2)
        {
            return false;
        }
        
        if (k == 0)
        {
            for (auto i = 1; i < std::size(nums); i++)
            {
                if (nums[i] == 0 && nums[i - 1] == 0)
                {
                    return true;
                }
            }
        }
        else
        {
            std::unordered_set<int> pref { 0 };        
            int sum = nums[0];

            for (auto i = 1; i < std::size(nums); i++)
            {
                if (pref.find((sum + nums[i]) % k) != pref.end())
                {
                    return true;
                }

                pref.insert(sum % k);
                sum += nums[i];
            }
        } 
        
        return false;
    }
};