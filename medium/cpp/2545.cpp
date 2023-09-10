// https://leetcode.com/problems/sort-the-students-by-their-kth-score/

class Solution
{
public:
    std::vector<std::vector<int>> sortTheStudents(std::vector<std::vector<int>>& score, int k)
    {
        std::sort(std::begin(score), std::end(score), [k](const auto& left, const auto& right) {
            return left[k] > right[k];
        });

        return score;
    }
};