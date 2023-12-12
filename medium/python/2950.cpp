// https://leetcode.com/problems/number-of-divisible-substrings/description/

class Solution:
    def countDivisibleSubstrings(self, word: str) -> int:
        mapping = [1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9]
        n = len(word)
        res = 0

        for i in range(0, n):
            s = 0
            for j in range(i, n):
                s += mapping[ord(word[j]) - ord('a')]
                if s % (j - i + 1) == 0:
                    res += 1

        return res
        