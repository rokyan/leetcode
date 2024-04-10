// https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/

class Solution
{
public:
    std::vector<int> beautifulIndices(std::string s, std::string a, std::string b, int k)
    {
        const auto ai = getIndices(s, a);
        const auto bi = getIndices(s, b);

        if (ai.empty() || bi.empty())
        {
            return {};
        }

        std::vector<int> res;

        for (auto aidx = 0, bidx = 0; aidx < std::size(ai); aidx++)
        {
            while (bidx + 1 < std::size(bi) && bi[bidx] <= ai[aidx] && ai[aidx] - bi[bidx] > k)
            {
                bidx++;
            }

            if (std::abs(ai[aidx] - bi[bidx]) <= k)
            {
                res.push_back(ai[aidx]);
            }
        }

        return res;
    }

private:
    static std::vector<int> getIndices(const std::string& s, const std::string& pattern)
    {
        const auto n = std::size(s);
        const auto m = std::size(pattern);

        std::vector<int> indices;

        for (auto i = 0; i + m - 1 < n; i++)
        {
            auto match = true;

            for (auto j = i; j < i + m; j++)
            {
                if (s[j] != pattern[j - i])
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                indices.push_back(i);
            }
        }

        return indices;
    }
};