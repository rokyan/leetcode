// https://leetcode.com/problems/vowels-game-in-a-string/description/

class Solution
{
public:
    bool doesAliceWin(const std::string& s)
    {
        const std::string vowels = "aeiou";

        for (auto c : s)
        {
            if (vowels.find(c) != std::string::npos)
            {
                return true;
            }
        }

        return false;
    }
};