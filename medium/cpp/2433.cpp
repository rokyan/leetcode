// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/

class Solution
{
public:
    std::vector<int> findArray(std::vector<int>& pref)
    {
        const auto n = std::size(pref);
        
        std::vector<int> arr(pref);
        
        for (std::size_t i = 1; i < n; i++)
        {
            arr[i] = pref[i] ^ pref[i - 1];
        }
        
        return arr;
    }
};