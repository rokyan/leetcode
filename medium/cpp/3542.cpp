// https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero/description/

class Solution
{
public:
    int minOperations(const std::vector<int>& nums)
    {
        const auto n = std::size(nums);

        std::vector<int> st;
        st.reserve(n);
        std::vector<int> left(n, -1);

        for (auto i = 0; i < std::size(nums); i++)
        {
            while (!st.empty() && nums[st.back()] >= nums[i])
            {
                st.pop_back();
            }

            if (!st.empty())
            {
                left[i] = st.back();
            }

            st.push_back(i);
        }

        std::unordered_map<int, int> lastPos;
        auto res = 0;

        for (auto i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                continue;
            }

            if (const auto it = lastPos.find(nums[i]); it != std::end(lastPos))
            {
                if (it->second > left[i])
                {
                    continue;
                }
            }

            lastPos[nums[i]] = i;
            res++;
        }

        return res;   
    }
};