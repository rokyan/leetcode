// https://leetcode.com/problems/minimum-operations-to-make-subarray-elements-equal/description/

class Solution
{
public:
    long long minOperations(const std::vector<int>& nums, int k)
    {
        std::multiset<int> left;
        std::multiset<int> right;

        auto leftSum = 0LL;
        auto rightSum = 0LL;

        for (auto i = 0; i < k; i++)
        {
            right.insert(nums[i]);
            rightSum += nums[i];
        }

        const auto rightSize = (k + 1) / 2;

        while (std::size(right) > rightSize)
        {
            left.insert(*std::cbegin(right));
            leftSum += *std::cbegin(right);
            rightSum -= *std::cbegin(right);
            right.erase(std::cbegin(right));
        }

        auto res = meow(leftSum, rightSum, *std::cbegin(right), k);

        if (k % 2 == 0)
        {
            res = std::min(res, meow(leftSum, rightSum, *std::crbegin(left), k));
        }

        const auto n = std::size(nums);

        for (auto i = k; i < n; i++)
        {
            if (nums[i] >= *std::cbegin(right))
            {
                right.insert(nums[i]);
                rightSum += nums[i];
            }
            else
            {
                left.insert(nums[i]);
                leftSum += nums[i];
            }
            
            if (const auto it = left.find(nums[i - k]); it != std::cend(left))
            {
                leftSum -= *it;
                left.erase(it);
            }
            else
            {
                const auto jt = right.find(nums[i - k]);
                rightSum -= *jt;
                right.erase(jt);
            }

            while (std::size(left) > k / 2)
            {
                rightSum += *std::crbegin(left);
                leftSum -= *std::crbegin(left);
                right.insert(*std::crbegin(left));
                left.erase(--std::cend(left));
            }

            while (std::size(right) > (k + 1) / 2)
            {
                rightSum -= *std::cbegin(right);
                leftSum += *std::cbegin(right);
                left.insert(*std::cbegin(right));
                right.erase(std::cbegin(right));
            }

            res = std::min(res, meow(leftSum, rightSum, *std::cbegin(right), k));

            if (k % 2 == 0)
            {
                res = std::min(res, meow(leftSum, rightSum, *std::crbegin(left), k));
            }
        }

        return res;
    }

private:
    long long meow(long long leftSum, long long rightSum, long long med, int k)
    {
        auto total = (k / 2 * med - leftSum) + (rightSum - (k + 1) / 2 * med);
        return total;
    }
};