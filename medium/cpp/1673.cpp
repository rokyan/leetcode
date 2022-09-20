// https://leetcode.com/problems/find-the-most-competitive-subsequence/

class Solution
{
public:
    std::vector<int> mostCompetitive(std::vector<int>& nums, int k)
    {
        std::vector<int> st;
        st.push_back(nums.front());
        
        for (std::size_t i = 1; i < std::size(nums); i++)
        {
            int rem = std::size(nums) - i;
            
            while (!st.empty() && st.back() > nums[i] && std::size(st) + rem > k)
            {
                st.pop_back();
            }
            
            if (std::size(st) < k)
            {
                st.push_back(nums[i]);
            }
        }
        
        return st;
    }
};