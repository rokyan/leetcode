# https://leetcode.com/problems/shifting-letters/

class Solution:
    def shiftingLetters(self, s: str, shifts: List[int]) -> str:
        acc = 0
        res = []

        for i in range(len(s) - 1, -1, -1):
            res.append(chr(ord('a') + (ord(s[i]) - ord('a') + shifts[i] + acc) % 26))
            acc = (acc + shifts[i]) % 26

        return ''.join(res)[::-1]