// https://leetcode.com/problems/multiply-strings/description/

class Solution
{
public:
    std::string multiply(std::string num1, std::string num2)
    {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        
        std::vector<std::string> nums;
        nums.reserve(std::size(num2));

        for (auto i = static_cast<int>(std::size(num2)) - 1, pad = 0; i >= 0; i--, pad++)
        {
            nums.push_back(mult(num1, num2[i] - '0', pad));
        }

        auto tot = std::size(nums.front());

        for (auto&& num : nums)
        {
            tot = std::max(tot, std::size(num));
        }

        auto carry = 0;

        std::string res;
        res.reserve(tot);


        for (auto i = 0; i < tot; i++)
        {
            for (auto&& num : nums)
            {
                if (i < std::size(num))
                {
                    carry += num[i] - '0';
                }
            }

            res.push_back(carry % 10 + '0');
            carry /= 10;
        }

        while (carry > 0)
        {
            res.push_back(carry % 10 + '0');
            carry /= 10;            
        }

        std::reverse(std::begin(res), std::end(res));

        return res;
    }

private:
    std::string mult(const std::string& num, int d, int pad = 0)
    {
        std::string res;

        while (pad--)
        {
            res.push_back('0');
        }

        auto carry = 0;

        for (auto i = static_cast<int>(std::size(num)) - 1; i >= 0; i--)
        {
            carry += (num[i] - '0') * d;
            res.push_back('0' + carry % 10);
            carry /= 10;
        }

        while (carry > 0)
        {
            res.push_back('0' + carry % 10);
            carry /= 10; 
        }

        return res;
    }
};