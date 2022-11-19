// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

class Solution
{
public:
    int minPartitions(std::string n)
    {
        return *std::max_element(std::begin(n), std::end(n)) - '0';
    }
};