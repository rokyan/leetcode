// https://leetcode.com/problems/first-element-with-unique-frequency/description/

class Solution
{
public:
    int firstUniqueFreq(const std::vector<int>& nums)
    {
        std::unordered_map<int, int> freq;

        for (int num : nums)
        {
            freq[num]++;
        }

        std::unordered_map<int, int> freqOfFreq;

        for (const auto [num, f] : freq)
        {
            freqOfFreq[f]++;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (freqOfFreq[freq[nums[i]]] == 1)
            {
                return nums[i];
            }
        }

        return -1;
    }
};