# https://leetcode.com/problems/find-k-length-substrings-with-no-repeated-characters/description/

class Solution:
    def numKLenSubstrNoRepeats(self, s: str, k: int) -> int:
        freq = [0] * 26
        cnt = 0
        res = 0

        for i in range(0, len(s)):
            if freq[ord(s[i]) - ord('a')] == 0:
                cnt += 1
            freq[ord(s[i]) - ord('a')] += 1

            if i >= k - 1:
                if cnt == k:
                    res += 1
                if freq[ord(s[i - k + 1]) - ord('a')] == 1:
                    cnt -= 1
                freq[ord(s[i - k + 1]) - ord('a')] -= 1

        return res

