// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/

class Solution
{
public:
    int countTriplets(std::vector<int>& arr)
    {
        const auto n = std::size(arr);
        
        std::vector<int> pref(arr);
        
        for (std::size_t i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] ^ arr[i];
        }
        
        auto total = 0;
        
        for (std::size_t i = 0; i + 1 < n; i++)
        {
            for (std::size_t j = i + 1; j < n; j++)
            {
                if ((i > 0 ? pref[i - 1] : 0) == pref[j])
                {
                    total += j - i;
                }
            }
        }
        
        return total;
    }
};