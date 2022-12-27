// https://leetcode.com/problems/maximum-product-of-word-lengths/description/

class Solution
{
public:
    int maxProduct(std::vector<std::string>& words)
    {
        auto ans = 0;
        
        for (auto i = 0; i < std::size(words); ++i)
        {
            for (auto j = 0; j < i; ++j)
            {
                if (!hasCommonLetter(words[i], words[j]))
                {
                    ans = std::max<int>(ans, std::size(words[i]) * std::size(words[j]));
                }
            }
        }
        
        return ans;
    }

private:   
    bool hasCommonLetter(const std::string& lhs, const std::string& rhs)
    {
        int counter[26] { 0 };
        
        for (auto c : lhs)
        {
            ++counter[c - 'a'];
        }
        
        for (auto c : rhs)
        {
            if (counter[c - 'a'] > 0)
            {
                return true;
            }
        }

        return false;
    }
};