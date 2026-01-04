// https://leetcode.com/problems/four-divisors/description/

class Solution
{
public:
    int sumFourDivisors(const std::vector<int>& nums)
    {
        return std::accumulate(nums.cbegin(), nums.cend(), 0, [this](int acc, int num) {
            return acc + calc(num);
        });
    }

private:
    int calc(int num)
    {
        int cnt = 0;
        int sum = 0;

        for (int div = 1; div * div <= num && cnt <= 4; div++)
        {
            if (num % div == 0)
            {
                cnt += 2;
                sum += div + num / div;

                if (div * div == num)
                {
                    cnt--;
                    sum -= div;
                }
            }
        }

        return cnt == 4 ? sum : 0;
    }
};