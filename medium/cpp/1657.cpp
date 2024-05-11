// https://leetcode.com/problems/determine-if-two-strings-are-close/description/

class Solution
{
public:
    bool closeStrings(std::string word1, std::string word2)
    {
        std::array<int, 26> freq1{ 0 }, freq2{ 0 };

        for (auto c : word1)
        {
            freq1[c - 'a']++;
        }

        for (auto c : word2)
        {
            freq2[c - 'a']++;
        }

        for (auto i = 0; i < 26; i++)
        {
            if (freq1[i] != 0 && freq2[i] == 0 || freq1[i] == 0 && freq2[i] != 0)
            {
                return false;
            }
        }

        std::sort(std::begin(freq1), std::end(freq1));
        std::sort(std::begin(freq2), std::end(freq2));

        for (auto i = 0; i < 26; i++)
        {
            if (freq1[i] != freq2[i])
            {
                return false;
            }
        }

        return true;
    }
};