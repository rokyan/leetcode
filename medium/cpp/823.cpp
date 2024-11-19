// https://leetcode.com/problems/binary-trees-with-factors/description/

class Solution
{
private:
    static constexpr auto mod = 1000'000'000 + 7;

public:
    int numFactoredBinaryTrees(std::vector<int>& arr)
    {
        const auto n = std::size(arr);

        std::sort(std::begin(arr), std::end(arr));

        std::unordered_map<int, int> res;

        for (auto i = 0; i < n; i++)
        {
            res[arr[i]] = 1;

            for (auto j = 0; j < i && 1LL * arr[j] * arr[j] <= arr[i]; j++)
            {
                if (arr[i] % arr[j] == 0)
                {
                    const auto r = arr[i] / arr[j];

                    if (res.find(r) != std::end(res))
                    {
                        res[arr[i]] += 1LL * res[arr[j]] * res[r] * (arr[j] == r ? 1 : 2) % mod;
                        res[arr[i]] %= mod;
                    }
                }
            }
         }

         auto tot = 0;

         for (const auto [key, value] : res)
         {
            tot += value;
            tot %= mod;
         }

         return tot;
    }
};