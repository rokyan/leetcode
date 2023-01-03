// https://leetcode.com/problems/permutations/description/

class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::vector<std::vector<int>> permutations;
        generate(0, nums, permutations);
        return permutations;
    }

private:
    void generate(std::size_t pos, std::vector<int>& permutation, std::vector<std::vector<int>>& permutations)
    {
        if (pos == std::size(permutation))
        {
            permutations.push_back(permutation);
            return;
        }
        
        for (auto i = pos; i < std::size(permutation); ++i)
        {
            std::swap(permutation[pos], permutation[i]);
            generate(pos + 1, permutation, permutations);
            std::swap(permutation[pos], permutation[i]);
        }
    }
};