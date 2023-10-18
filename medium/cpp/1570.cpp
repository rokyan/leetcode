// https://leetcode.com/problems/dot-product-of-two-sparse-vectors/description/

class SparseVector
{
public:
    
    SparseVector(std::vector<int> &nums)
    {
        data.reserve(std::size(nums));

        for (auto i = 0; i < std::size(nums); i++)
        {
            if (nums[i])
            {
                data.emplace_back(i, nums[i]);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec)
    {
        auto res = 0;

        for (auto i = 0, j = 0; i < std::size(data) && j < std::size(vec.data); i++)
        {
            while (j < std::size(vec.data) && vec.data[j].first < data[i].first)
            {
                j++;
            }

            if (j < std::size(vec.data) && vec.data[j].first == data[i].first)
            {
                res += vec.data[j].second * data[i].second;
            }
        }

        return res;
    }

private:
    std::vector<std::pair<int, int>> data;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);