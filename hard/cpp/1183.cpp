// https://leetcode.com/problems/maximum-number-of-ones/description/

class Solution
{
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes)
    {
        std::vector<int> cnt;
        cnt.reserve(width * height);

        for (auto r = 1; r <= sideLength; r++)
        {
            for (auto c = 1; c <= sideLength; c++)
            {
                const auto t1 = width / sideLength
                    + (width % sideLength ? r <= width % sideLength : 0);
                const auto t2 = height / sideLength
                    + (height % sideLength ? c <= height % sideLength : 0);

                cnt.push_back(t1 * t2);
            }
        }

        std::ranges::sort(cnt, std::greater<>{});

        auto res = 0;

        for (auto i = 0; i < maxOnes; i++)
        {
            res += cnt[i];
        }

        return res;
    }
};