// https://leetcode.com/problems/range-sum-query-mutable/

class NumArray
{
public:
    NumArray(vector<int>& nums)
        : size(std::size(nums))
    {
        data.resize(size * 4);
            
            build_tree(1, 0, size - 1, nums);
    }
    
    void update(int index, int val)
    {
        update_tree(1, index, val, 0, size - 1);
    }
    
    int sumRange(int left, int right)
    {
        return sum_tree(1, left, right, 0, size - 1);
    }
    
private:
    void build_tree(std::size_t idx, std::size_t left, std::size_t right, const std::vector<int>& nums)
    {
        if (left == right)
        {
            data[idx] = nums[left];
        }
        else
        {
            const std::size_t mid = left + (right - left) / 2;
            
            build_tree(idx * 2, left, mid, nums);
            build_tree(idx * 2 + 1, mid + 1, right, nums);
            
            data[idx] = data[idx * 2] + data[idx * 2 + 1];
        }
    }
    
    void update_tree(std::size_t idx, std::size_t pos, int val, std::size_t tree_left, std::size_t tree_right)
    {
        if (tree_left == tree_right)
        {
            data[idx] = val;
        }
        else
        {
            const std::size_t mid = tree_left + (tree_right - tree_left) / 2;
            
            if (pos <= mid)
            {
                update_tree(idx * 2, pos, val, tree_left, mid);
            }
            else
            {
                update_tree(idx * 2 + 1, pos, val, mid + 1, tree_right);
            }
            
            data[idx] = data[idx * 2] + data[idx * 2 + 1];
        }
    }
    
    int sum_tree(std::size_t idx, std::size_t left, std::size_t right, std::size_t tree_left, std::size_t tree_right)
    {
        if (left == tree_left && right == tree_right)
        {
            return data[idx];
        }
        
        const std::size_t mid = tree_left + (tree_right - tree_left) / 2;
        
        if (right <= mid)
        {
            return sum_tree(idx * 2, left, right, tree_left, mid);
        }
        
        if (left >= mid + 1)
        {
            return sum_tree(idx * 2 + 1, left, right, mid + 1, tree_right);
        }
        
        return sum_tree(idx * 2, left, mid, tree_left, mid) + sum_tree(idx * 2 + 1, mid + 1, right, mid + 1, tree_right);
    }
    
private:
    std::size_t size;
    std::vector<int> data;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */