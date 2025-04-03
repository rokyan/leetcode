class NumArray
{
public:
    NumArray(const std::vector<int>& nums)
    {
        ps.resize(std::size(nums));
        std::partial_sum(std::cbegin(nums), std::cend(nums), std::begin(ps));
    }
    
    int sumRange(int left, int right)
    {
        return ps[right] - (left > 0 ? ps[left - 1] : 0);
    }

private:
    std::vector<int> ps;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */