// https://leetcode.com/problems/string-compression-iii/description/

class Solution
{
public:
    std::string compressedString(const std::string& word)
    {
        auto compressed = std::string{};

        for (auto i = 0; i < std::size(word); )
        {
            auto cnt = 0;
            auto start = i;

            while (cnt < 9 && word[i + cnt] == word[start])
            {
                cnt++;
            }

            compressed.push_back('0' + cnt);
            compressed.push_back(word[i]);

            i = start + cnt;
        }

        return compressed;
    }
};