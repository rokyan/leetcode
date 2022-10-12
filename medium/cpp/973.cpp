// https://leetcode.com/problems/k-closest-points-to-origin/

class Solution
{
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k)
    {
        const auto comp = [](const auto& left, const auto& right)
        {
            const auto dst_left = left[0] * left[0] + left[1] * left[1];
            const auto dst_right = right[0] * right[0] + right[1] * right[1];
            
            return dst_left < dst_right;
        };
        
        std::nth_element(std::begin(points), std::begin(points) + k - 1, std::end(points), comp);
        
        return std::vector<std::vector<int>>(std::begin(points), std::begin(points) + k);
    }
};