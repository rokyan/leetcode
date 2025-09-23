// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/description/

class FindSumPairs
{
public:
    FindSumPairs(const std::vector<int>& nums1, const std::vector<int>& nums2)
        : nums1{nums1}
        , nums2{nums2}
    {
        for (auto num : nums2)
        {
            freq[num]++;
        }
    }
    
    void add(int index, int val)
    {
        freq[nums2[index]]--;
        nums2[index] += val;
        freq[nums2[index]]++;
    }
    
    int count(int tot)
    {
        auto res = 0;

        for (auto num : nums1)
        {
            res += freq[tot - num];
        }

        return res;
    }

private:
    std::vector<int> nums1;
    std::vector<int> nums2;
    std::unordered_map<int, int> freq;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */