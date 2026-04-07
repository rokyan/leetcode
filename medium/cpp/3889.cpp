// https://leetcode.com/problems/mirror-frequency-distance/description/

class Solution
{
public:
    int mirrorFrequency(const std::string& s)
    {
        std::unordered_map<char, int> freq;

        for (char c : s)
        {
            freq[c]++;
        }

        int res = 0;

        for (int i = 0; i < 13; i++)
        {
            res += std::abs(freq['a' + i] - freq['a' + 25 - i]);
        }

        for (int i = 0; i < 5; i++)
        {
            res += std::abs(freq['0' + i] - freq['0' + 9 - i]);
        }

        return res;
    }
};