// https://leetcode.com/problems/find-unique-binary-string/description/

class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        probe = set(int(num, 2) for num in nums)
        n = len(nums)

        for num in range(0, n + 1):
            if num not in probe:
                return bin(num)[2:].rjust(n, "0")

        return ""