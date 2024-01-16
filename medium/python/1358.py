# https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        cnt = [0] * 3
        l, r = 0, 0
        res = 0

        while r < len(s):
            cnt[ord(s[r]) - ord('a')] += 1

            while cnt[ord(s[l]) - ord('a')] > 1:
                cnt[ord(s[l]) - ord('a')] -= 1
                l += 1

            if all(cnt):
                res += l + 1

            r += 1
            
        return res