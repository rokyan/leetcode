class Solution
{
public:
    long long maxCaloriesBurnt(std::vector<int>& heights)
    {
        const int n = std::size(heights);
        int left = 0;
        int right = n - 1;
        bool takeRight = true;
        int last = 0;
        long long res = 0;

        std::ranges::sort(heights);

        for (int times = 0; times < n; times++)
        {
            if (takeRight)
            {
                res += sq(heights[right] - last);
                last = heights[right--];
            }
            else
            {
                res += sq(heights[left] - last);
                last = heights[left++];
            }
            takeRight ^= true;
        }

        return res;
    }

private:
    long long sq(int x)
    {
        return 1LL * x * x;
    }
};