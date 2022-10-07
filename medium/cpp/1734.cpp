// https://leetcode.com/problems/decode-xored-permutation/

class Solution
{
public:
    std::vector<int> decode(std::vector<int>& encoded)
    {
        const auto n = std::size(encoded);
        
        auto prev = encoded[0];
        auto val = encoded[0];
        
        for (std::size_t i = 1; i < n; i++)
        {
            auto cur = prev ^ encoded[i];
            val ^= cur;
            prev = cur;
        }
        
        for (int num = 1; num <= n + 1; num++)
        {
            val ^= num;
        }
        
        std::vector<int> res(n + 1);
        
        res[0] = val;
        
        for (std::size_t i = 1; i < n + 1; i++)
        {
            res[i] = res[i - 1] ^ encoded[i - 1];
        }
        
        return res;
    }
};