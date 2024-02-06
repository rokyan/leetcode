# https://leetcode.com/problems/number-of-wonderful-substrings/

class Solution:
    def wonderfulSubstrings(self, word: str) -> int:
        cnt = defaultdict(int)
        cnt[0] = 1

        mask = 0
        
        res = 0

        for i in range(0, len(word)):
            mask ^= 1 << (ord(word[i]) - ord('a'))
            res += cnt[mask]

            for b in range(0, 10):
                res += cnt[mask ^ (1 << b)]

            cnt[mask] += 1

        return res