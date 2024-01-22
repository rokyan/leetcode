// https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

class Solution
{
private:
    struct state
    {
        state(double val, int num_idx, int den_idx)
            : val{ val }
            , num_idx{ num_idx }
            , den_idx{ den_idx }
        {}

        bool operator<(const state& other) const noexcept
        {
            return val < other.val;
        }

        double val;
        int num_idx;
        int den_idx;
    };

public:
    std::vector<int> kthSmallestPrimeFraction(std::vector<int>& arr, int k)
    {
        const auto n = static_cast<int>(std::size(arr));

        std::priority_queue<state> heap;
        heap.push({ -1.0 * arr.front() / arr.back(), 0, n - 1 });

        std::unordered_set<double> probe;

        while (--k)
        {
            const auto s = heap.top();
            heap.pop();

            // std::cout << arr[s.num_idx] << "/" << arr[s.den_idx] << std::endl;

            if (s.num_idx + 1 < n)
            {
                const auto val = -1.0 * arr[s.num_idx + 1] / arr[s.den_idx];
                if (probe.insert(val).second) heap.push({ val, s.num_idx + 1, s.den_idx });
            }

            if (s.den_idx > 0)
            {
                const auto val = -1.0 * arr[s.num_idx] / arr[s.den_idx - 1];
                if (probe.insert(val).second) heap.push({ val, s.num_idx, s.den_idx - 1 });
            }
        }

        const auto& s = heap.top();

        return { arr[s.num_idx], arr[s.den_idx] };
    }
};