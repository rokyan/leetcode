// https://leetcode.com/problems/neighboring-bitwise-xor/description/

class Solution
{
public:
    bool doesValidArrayExist(std::vector<int>& derived)
    {
        return check(0, derived) || check(1, derived);
    }

private:
    bool check(int value, const std::vector<int>& derived)
    {
        auto next = value;

        for (auto i = static_cast<int>(std::size(derived)) - 1; i >= 0; i--)
        {
            next = derived[i] ^ next;
        }

        return next == value;
    }
};