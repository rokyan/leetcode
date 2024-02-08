// https://leetcode.com/problems/find-smallest-common-element-in-all-rows/

class Solution:
    def smallestCommonElement(self, mat: List[List[int]]) -> int:
        cnt = defaultdict(int)

        for i in range(0, len(mat)):
            for num in mat[i]:
                cnt[num] += 1

        for key in sorted(cnt):
            if cnt[key] == len(mat):
                return key

        return -1
        