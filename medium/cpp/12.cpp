// https://leetcode.com/problems/integer-to-roman/

class Solution
{
public:
    string intToRoman(int num)
    {       
        std::string thousands[4] = { "", "M", "MM", "MMM" };
        std::string hundreds[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        std::string tens[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        std::string singles[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
        
        return thousands[num / 1000] + hundreds[(num % 1000) / 100] + tens[(num % 100) / 10] + singles[num % 10];
    }
};