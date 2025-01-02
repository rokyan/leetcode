// https://leetcode.com/problems/maximum-compatibility-score-sum/description/

class Solution:
    def maxCompatibilitySum(self, students: List[List[int]], mentors: List[List[int]]) -> int:
        m = len(students)
        score = 0

        for perm in permutations(range(0, m)):
            cur = 0
            for i in range(0, m):
                cur += sum(x == y for x, y in zip(students[i], mentors[perm[i]]))
            score = max(score, cur)

        return score