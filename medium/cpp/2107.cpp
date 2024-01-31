// https://leetcode.com/problems/number-of-unique-flavors-after-sharing-k-candies/

class Solution
{
public:
    int shareCandies(vector<int>& candies, int k)
    {
        std::unordered_map<int, int> freq;

        for (auto c : candies)
        {
            freq[c]++;
        }

        auto tot = static_cast<int>(std::size(freq));

        for (auto i = 0; i < k; i++)
        {
            if (freq[candies[i]]-- == 1)
            {
                tot--;
            }
        }

        auto res = tot;

        for (auto i = k; i < std::size(candies); i++)
        {
            if (freq[candies[i]]-- == 1)
            {
                tot--;
            }

            if (freq[candies[i - k]]++ == 0)
            {
                tot++;
            }

            res = std::max(res, tot);
        }

        return res;
    }
};