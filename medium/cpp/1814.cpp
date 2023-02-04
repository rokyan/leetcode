// https://leetcode.com/problems/count-nice-pairs-in-an-array/description/

class Solution
{
private:
    static constexpr auto mod = 1000 * 1000 * 1000 + 7;

public:
    int countNicePairs(std::vector<int>& nums)
    {
        const auto rev = [](auto x) {
            auto ret = 0;

            while (x > 0)
            {
                ret = 10 * ret + x % 10;
                x /= 10;
            }

            return ret;
        };

        std::unordered_map<int, int> cnt;

        auto res = 0;

        for (const auto num : nums)
        {
            const auto val = num - rev(num);

            const auto it = cnt.find(val);

            if (it != std::end(cnt))
            {
                res += it->second;
                res %= mod;
                it->second++;
            }
            else
            {
                cnt.insert({ val, 1 });
            }
        }

        return res;
    }
};  