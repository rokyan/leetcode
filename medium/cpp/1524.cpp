// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int numOfSubarrays(std::vector<int>& arr)
    {
        auto odd = 0;
        auto even = 1;
        auto res = 0;
        auto s = 0LL;

        for (auto e : arr)
        {
            s += e;

            if (s % 2)
            {
                res += even;
                odd++;
            }
            else
            {
                res += odd;
                even++;
            }

            res %= mod;
        }

        return res;
    }
};