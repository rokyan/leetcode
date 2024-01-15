// https://leetcode.com/problems/bulls-and-cows/description/

class Solution
{
public:
    std::string getHint(std::string secret, std::string guess)
    {
        std::array<int, 10> s{ 0 };
        std::array<int, 10> g{ 0 };

        auto bulls = 0;

        for (auto i = 0; i < std::size(guess); i++)
        {
            if (secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                s[secret[i] - '0']++;
                g[guess[i] - '0']++;
            }
        }

        auto cows = 0;

        for (auto i = 0; i < 10; i++)
        {
            cows += std::min(s[i], g[i]);
        }

        return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
    }
};