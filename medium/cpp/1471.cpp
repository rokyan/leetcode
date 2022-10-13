// https://leetcode.com/problems/the-k-strongest-values-in-an-array/

class Solution
{
public:
    std::vector<int> getStrongest(std::vector<int>& arr, int k)
    {
        std::sort(std::begin(arr), std::end(arr));
        
        const auto n = std::size(arr);
        
        const auto median = arr[(n - 1) / 2];
        
        std::vector<int> answer(k);
        
        for (int i = 0, j = n - 1, t = 0; t < k; t++)
        {
            if (std::abs(arr[i] - median) <= std::abs(arr[j] - median))
            {
                answer[t] = arr[j--];
            }
            else
            {
                answer[t] = arr[i++];
            }
        }
        
        return answer;
    }
};