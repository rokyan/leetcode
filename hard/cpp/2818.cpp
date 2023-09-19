// https://leetcode.com/problems/apply-operations-to-maximize-score/description/

class Solution
{
private:
    static constexpr auto mod = 1000 * 1000 * 1000 + 7;

private:
    struct segment
    {
        segment() = default;

        segment(int value, long long weight)
            : value{ value }
            , weight{ weight }
        {}

        bool operator<(const segment& o) const
        {
            return value > o.value || value == o.value && weight < o.weight;
        }
        
        int value = 0;
        long long weight = 0LL;
    };

public:
    int maximumScore(std::vector<int>& nums, int k)
    {
        const auto n = std::size(nums);

        std::vector<int> score(n);

        for (auto i = 0; i < n; i++)
        {
            auto copied = nums[i];

            for (auto j = 2; j * j <= copied; j++)
            {
                if (copied % j == 0)
                {
                    score[i]++;

                    while (copied % j == 0)
                    {
                        copied /= j;
                    }
                }
            }

            if (copied > 1)
            {
                score[i]++;
            }
        }

        std::vector<int> left(n, -1);
        std::vector<int> right(n, n);

        std::vector<int> st;

        for (auto i = 0; i < n; i++)
        {
            while (!st.empty() && score[st.back()] < score[i])
            {
                st.pop_back();
            }

            if (!st.empty())
            {
                left[i] = st.back();
            }

            st.push_back(i);
        }

        st.clear();

        for (auto i = static_cast<int>(n) - 1; i >= 0; i--)
        {
            while (!st.empty() && score[st.back()] <= score[i])
            {
                st.pop_back();
            }

            if (!st.empty())
            {
                right[i] = st.back();
            }

            st.push_back(i);
        }

        std::vector<segment> s(n);

        for (auto i = 0; i < n; i++)
        {
            s[i] = segment{ nums[i], 1LL * (i - left[i]) * (right[i] - i) };
        }

        std::sort(std::begin(s), std::end(s));

        auto res = 1LL;

        for (auto i = 0; i < n && k > 0; i++)
        {
            const auto& cur = s[i];

            res *= pow(cur.value, std::min<long long>(cur.weight, k));
            res %= mod;

            k -= cur.weight;
        }

        return res;
    }

private:
    long long pow(long long x, int p)
    {
        if (p == 1)
        {
            return x;
        }

        if (p & 1)
        {
            return x * pow(x, p - 1) % mod;
        }

        const auto val = pow(x, p / 2);
        return val * val % mod;
    }
};