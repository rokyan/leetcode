# https://leetcode.com/problems/count-substrings-without-repeating-character/description/

class Solution:
    def numberOfSpecialSubstrings(self, s: str) -> int:
        freq = defaultdict(int)
        l = 0
        res = 0

        for r in range(0, len(s)):
            freq[s[r]] += 1

            while freq[s[r]] > 1:
                freq[s[l]] -= 1
                l += 1

            res += r - l + 1

        return res