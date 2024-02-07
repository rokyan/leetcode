# https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/

class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        k %= sum(chalk)
        res = 0

        while k >= chalk[res]:
            k -= chalk[res]
            res += 1

        return res