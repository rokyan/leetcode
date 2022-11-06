// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/

class Solution
{
public:
    int numOfSubarrays(std::vector<int>& arr, int k, int threshold)
    {
        auto subarr_sum = 0;
        
        for (std::size_t idx = 0; idx < k; idx++)
        {
            subarr_sum += arr[idx];
        }

        auto answer = subarr_sum / k >= threshold;
        
        for (std::size_t idx = 1; idx + k - 1 < std::size(arr); idx++)
        {
            subarr_sum -= arr[idx - 1];
            subarr_sum += arr[idx + k - 1];
            
            answer += subarr_sum / k >= threshold;
        }
        
        return answer;            
    }
};