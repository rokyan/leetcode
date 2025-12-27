// https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs/description/

class Solution
{
public:
    int minMirrorPairDistance(const std::vector<int>& nums)
    {
        std::unordered_map<int, int> last;

        const int n = std::size(nums);

        std::optional<int> res;

        for (int i = 0; i < n; i++)
        {
            if (const auto it = last.find(nums[i]); it != last.cend())
            {
                res = res ? std::min(res.value(), i - it->second) : i - it->second;
            }

            last[rev(nums[i])] = i;
        }

        return res ? res.value() : -1;
    }

private:
    int rev(int x)
    {
        int res = 0;

        while (x)
        {
            res = 10 * res + x % 10;
            x /= 10;
        }

        return res;
    }
};