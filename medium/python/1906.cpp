# https://leetcode.com/problems/minimum-absolute-difference-queries/description/

class Solution:
    def minDifference(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        pref = []

        for i in range(0, len(nums)):
            cur = [0] * 100 if i == 0 else pref[-1][:]
            cur[nums[i] - 1] += 1
            pref.append(cur)

        res = [-1] * len(queries)

        for i in range(0, len(queries)):
            l, r = queries[i][0], queries[i][1]
            last = -1

            for v in range(0, 100):
                d = pref[r][v] - (pref[l - 1][v] if l > 0 else 0)
                if d > 0:
                    if last != -1:
                        res[i] = v - last if res[i] == -1 else min(res[i], v - last)
                    last = v

        return res
        