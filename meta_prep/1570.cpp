class SparseVector
{
public:    
    SparseVector(const std::vector<int>& nums)
    {
        for (auto idx = 0; idx < std::size(nums); idx++)
        {
            if (nums[idx] != 0)
            {
                idxs.emplace_back(idx, nums[idx]);
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(const SparseVector& vec)
    {
        auto res = 0;

        const auto n = std::size(idxs);
        const auto m = std::size(vec.idxs);

        for (auto i = 0, j = 0; i < n && j < m; )
        {
            if (idxs[i].first < vec.idxs[j].first)
            {
                i++;
            }
            else if (idxs[i].first > vec.idxs[j].first)
            {
                j++;
            }
            else
            {
                res += idxs[i].second * vec.idxs[j].second;
                i++;
                j++;
            }
        }

        return res;
    }

private:
    std::vector<std::pair<int, int>> idxs;
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);