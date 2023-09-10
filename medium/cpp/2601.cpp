// https://leetcode.com/problems/prime-subtraction-operation/description/

class Solution
{
public:
    bool primeSubOperation(std::vector<int>& nums)
    {
        std::vector<int> primes;

        for (auto num = 2; num <= *std::max_element(std::begin(nums), std::end(nums)); num++)
        {
            auto prime = true;

            for (auto d = 2; d * d <= num && prime; d++)
            {
                if (num % d == 0)
                {
                    prime = false;
                }
            }

            if (prime)
            {
                primes.push_back(num);
            }
        }

        for (auto i = 0, prev = 0; i < std::size(nums); i++)
        {
            auto j = -1;

            while (j + 1 < std::size(primes) && nums[i] - primes[j + 1] > prev)
            {
                j++;
            }

            if (j != -1)
            {
                nums[i] -= primes[j];
            }

            if (nums[i] <= prev)
            {
                return false;
            }

            prev = nums[i];
        }

        return true;
    }
};