// https://leetcode.com/problems/split-array-with-equal-sum/description/

class Solution
{
public:
    bool splitArray(const std::vector<int>& nums)
    {
        const int n = nums.size();

        std::vector<std::unordered_set<int>> validSplits(n);

        int sum = std::accumulate(nums.begin(), nums.end(), 0);

        for (int i = 0; i < n; i++)
        {
            sum -= nums[i];

            int ls = nums[i];
            int rs = sum;

            for (int j = i + 1; j + 1 < n; j++)
            {
                rs -= nums[j];

                if (ls == rs)
                {
                    validSplits[i].insert(ls);
                }

                ls += nums[j];
            }
        }

        for (int i = 1, si = 0; i < n; i++)
        {
            si += nums[i - 1];

            for (int j = i + 2, sj = 0; j + 3 < n; j++)
            {
                sj += nums[j - 1];
    
                if (si == sj && validSplits[j + 1].count(si))
                {
                    return true;
                }
            }
        }

        return false;
    }
};