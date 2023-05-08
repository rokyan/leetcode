// https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/description/

class Solution
{
public:
    int maximumWhiteTiles(std::vector<std::vector<int>>& tiles, int carpetLen)
    {
        std::sort(std::begin(tiles), std::end(tiles));

        const auto n = static_cast<int>(std::size(tiles));

        auto res = 0;
        auto s = 0;

        for (auto left = 0, right = 0; left < n; )
        {
            while (right < n && tiles[right][1] - tiles[left][0] + 1 <= carpetLen)
            {
                s += tiles[right][1] - tiles[right][0] + 1;
                right++;
            }

            auto add = 0;

            if (right < n && tiles[right][0] - tiles[left][0] + 1 <= carpetLen)
            {
                add = carpetLen - (tiles[right][0] - tiles[left][0]);
            }

            res = std::max(res, s + add);

            s -= tiles[left][1] - tiles[left][0] + 1;

            left++;
            right = std::max(right, left);
        }

        return res;
    }
};