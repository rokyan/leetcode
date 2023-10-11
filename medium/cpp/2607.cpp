// https://leetcode.com/problems/make-k-subarray-sums-equal/description/

class Solution
{
public:
    long long makeSubKSumEqual(std::vector<int>& arr, int k)
    {
        std::vector<std::vector<int>> part(k);
        std::vector<char> vis(std::size(arr));

        for (auto i = 0; i < k; i++)
        {
            if (!vis[i])
            {
                for (auto j = i; !vis[j]; j = (j + k) % std::size(arr))
                {
                    part[i].push_back(arr[j]);
                    vis[j] = true;
                }
            }
        }

        auto res = 0LL;

        for (auto&& p : part)
        {
            if (p.empty())
            {
                continue;
            }

            std::sort(std::begin(p), std::end(p));

            auto sum = std::accumulate(std::begin(p), std::end(p), 0LL);
            auto psum = 0LL;

            auto cur = -1LL;

            for (auto i = 0; i < std::size(p); i++)
            {
                sum -= p[i];

                auto t = sum - p[i] * (std::size(p) - i - 1);
                t += 1LL * p[i] * i - psum;

                psum += p[i];

                cur = cur == -1 ? t : std::min<long long>(cur, t);
            }

            res += cur;
        }

        return res;
    }
};