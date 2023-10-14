// https://leetcode.com/problems/find-k-closest-elements/description/

class Solution
{
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x)
    {
        auto pos = static_cast<int>(std::distance(std::begin(arr), std::lower_bound(std::begin(arr), std::end(arr) - k, x)));

        std::vector<int> left, right;

        for (auto l = pos - 1, r = pos, times = 0; times < k; times++)
        {
            if (l < 0)
            {
                right.push_back(arr[r++]);
            }
            else if (r == std::size(arr))
            {
                left.push_back(arr[l--]);
            }
            else if (x - arr[l] <= arr[r] - x)
            {
                left.push_back(arr[l--]);
            }
            else
            {
                right.push_back(arr[r++]);
            }
        }

        std::reverse(std::begin(left), std::end(left));
        left.insert(std::end(left), std::begin(right), std::end(right));

        return left;
    }
};