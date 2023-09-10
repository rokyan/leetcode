// https://leetcode.com/problems/subsets/description/

class Solution
{
public:    
    std::vector<std::vector<int>> subsets(std::vector<int>& nums)
    {
        std::vector<int> cur;
        std::vector<std::vector<int>> ans;

        generate(0, std::size(nums), nums, cur, ans);
        
        return ans;
    }

private:
    void generate(int pos, int n, const std::vector<int>& nums,
        std::vector<int>& cur, std::vector<std::vector<int>>& ans)
    {
        if (pos == n)
        {
            ans.push_back(cur);
        }
        else
        {
            generate(pos + 1, n, nums, cur, ans);
            cur.push_back(nums[pos]);
            generate(pos + 1, n, nums, cur, ans);
            cur.pop_back();
        }
    }
};