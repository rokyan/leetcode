// https://leetcode.com/problems/next-greater-element-iii/description/

class Solution
{
public:
    int nextGreaterElement(int n)
    {
        auto s = std::to_string(n);
        std::next_permutation(std::begin(s), std::end(s));
        auto next = std::stoll(s);
        return next > n && next <= std::numeric_limits<int>::max() ? next : -1;
    }
};