// https://leetcode.com/problems/next-greater-element-ii/

class Solution
{
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums)
    {
        std::vector<int> st;
        
        for (int i = std::size(nums) - 1; i >= 0; i--)
        {
            const auto num = nums[i];
            
            while (!st.empty() && st.back() <= num)
            {
                st.pop_back();
            }
            
            st.push_back(num);
        }
        
        std::vector<int> answer(std::size(nums));
        
        for (int i = std::size(nums) - 1; i >= 0; i--)
        {
            const auto num = nums[i];
            
            while (!st.empty() && st.back() <= num)
            {
                st.pop_back();
            }
            
            answer[i] = st.empty() ? -1 : st.back();
            
            st.push_back(num);
        }
        
        return answer;
    }
};