// https://leetcode.com/problems/sum-of-subarray-ranges/

class Solution
{
public:
    long long subArrayRanges(std::vector<int>& nums)
    {            
        return solve(nums, std::less<>{}) - solve(nums, std::greater<>{});
    }
    
private:
    template<typename Comp>
    long long solve(const std::vector<int>& nums, Comp comp)
    {
        const auto n = std::size(nums);
        
        std::vector<int> st;
        st.reserve(n);
        
        std::vector<int> left(n, -1);
        std::vector<int> right(n, n);
        
        for (std::size_t i = 0; i < n; i++)
        {
            while (!st.empty() && comp(nums[st.back()], nums[i]))
            {
                right[st.back()] = i;
                st.pop_back();
            }
            
            if (!st.empty())
            {
                left[i] = st.back();    
            }
            
            st.push_back(i);
        }
               
        long long res = 0;
        
        for (std::size_t i = 0; i < n; i++)
        {
            res += 1LL * nums[i] * (i - left[i]) * (right[i] - i);
        }
        
        return res;
    }
};