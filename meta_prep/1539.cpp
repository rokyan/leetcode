class Solution
{
public:
    int findKthPositive(const std::vector<int>& arr, int k)
    {
        auto last = 0;

        const auto n = std::size(arr);

        for (auto i = 0; i < n; i++)
        {
            const auto diff = arr[i] - last - 1;

            if (diff >= k)
            {
                return last + k;
            }

            k -= diff;
            last = arr[i];
        }

        return last + k;
    }
};