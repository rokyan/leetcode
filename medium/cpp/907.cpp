// https://leetcode.com/problems/sum-of-subarray-minimums/

class Solution
{
private:
    static constexpr auto MOD = 1000000000 + 7;
    
public:
    int sumSubarrayMins(std::vector<int>& arr)
    {       
        const auto n = std::size(arr);
        
        std::vector<int> left_min(n, -1);
        std::vector<int> right_min(n, n);
        
        std::vector<int> st;
        
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.back()] > arr[i])
            {
                right_min[st.back()] = i;
                st.pop_back();
            }
            
            if (!st.empty())
            {
                left_min[i] = st.back();
            }
            
            st.push_back(i);
        }
        
        auto answer = 0LL;
        
        for (int i = 0; i < n; i++)
        {
            int left = i - left_min[i];
            int right = right_min[i] - i;
                       
            answer += 1LL * arr[i] * left * right;
            answer %= MOD;
        }
        
        return answer;
    }
};