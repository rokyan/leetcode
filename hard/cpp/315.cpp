// https://leetcode.com/problems/count-of-smaller-numbers-after-self/

class Solution
{
public:
    std::vector<int> countSmaller(std::vector<int>& nums)
    {
        remap(nums);
        
        init(nums);
        
        const auto sz = std::size(nums);
        
        std::vector<int> res(sz);
        
        for (int i = sz - 1; i >= 0; i--)
        {
            res[i] = sum(1, 0, sz - 1, 0, nums[i] - 1);
            update(1, 0, sz - 1, nums[i]);
        }
        
        return res;
    }
    
private:
    void remap(std::vector<int>& nums)
    {
        std::map<int, int> mapping;
        
        for (auto num : nums)
        {
            mapping[num] = 0;
        }
        
        int counter = 1;
        
        for (auto& entry : mapping)
        {
            entry.second = counter++;
        }
        
        for (auto& num : nums)
        {
            num = mapping[num];
        }
    }
    
    void init(const std::vector<int>& nums)
    {
        tree.resize(4 * std::size(nums) + 4);
    }
       
    void update(int v, int l, int r, int pos)
    {
        if (l == r)
        {
            tree[v]++;
        }
        else
        {
            const int mid = l + (r - l) / 2;
            
            if (pos <= mid)
            {
                update(v * 2, l, mid, pos);
            }
            else
            {
                update(v * 2 + 1, mid + 1, r, pos);
            }
            
            tree[v] = tree[v * 2] + tree[v * 2 + 1];
        }
    }
    
    int sum(int v, int l, int r, int ql, int qr)
    {
        if (l == ql && r == qr)
        {
            return tree[v];
        }
        else
        {
            const int mid = l + (r - l) / 2;
            
            if (qr <= mid)
            {
                return sum(v * 2, l, mid, ql, qr);
            }
            
            if (ql > mid)
            {
                return sum(v * 2 + 1, mid + 1, r, ql, qr);
            }
            
            return sum(v * 2, l, mid, ql, mid) + sum(v * 2 + 1, mid + 1, r, mid + 1, qr);
        }
    }
    
private:
    std::vector<int> tree;
};