// https://leetcode.com/problems/minimum-operations-to-make-binary-palindrome/description/

class Solution
{
public:
    std::vector<int> minOperations(const std::vector<int>& nums)
    {
        static constexpr int max_value = 5000;

        std::vector<int> dist(2 * max_value);

        for (int value = 1, last = 0; value <= max_value; value++)
        {
            if (is_palindrome(value))
            {
                last = value;
            }

            dist[value] = value - last;
        }

        for (int value = max_value, last = 10 * max_value; value >= 1; value--)
        {
            if (is_palindrome(value))
            {
                last = value;
            }

            const int upd_dist = last - value;

            if (upd_dist < dist[value])
            {
                dist[value] = upd_dist;
            }
        }

        std::vector<int> res(std::size(nums));

        for (int i = 0; i < std::size(nums); i++)
        {
            res[i] = dist[nums[i]];
        }

        return res;
    }

private:
    bool is_palindrome(int x)
    {
        int rev = 0;
        int cx = x;

        while (cx)
        {
            rev = (rev << 1) | (cx & 1);
            cx >>= 1;
        }

        return rev == x;
    }
};