// https://leetcode.com/problems/k-diff-pairs-in-an-array/description/

class Solution
{
public:
    int findPairs(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> freq;
        
        for (auto e : nums)
        {
            ++freq[e];
        }
        
        auto answer = 0;
        
        for (auto e : nums)
        {
            const auto value = e - k;
            const auto it = freq.find(value);

            if (it != std::end(freq))
            {
                if (k == 0 && it->second > 1 || k > 0)
                {
                    freq.erase(it);
                    answer++;
                }
            }
        }
        
        return answer;
    }
};