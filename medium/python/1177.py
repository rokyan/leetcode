// https://leetcode.com/problems/can-make-palindrome-from-substring/

class Solution:
    def canMakePaliQueries(self, s: str, queries: List[List[int]]) -> List[bool]:
        pref = []

        for i in range(0, len(s)):
            cur = [0] * 26 if i == 0 else pref[-1].copy()
            cur[ord(s[i]) - ord('a')] += 1
            pref.append(cur)

        res = [0] * len(queries)

        for idx, (l, r, k) in enumerate(queries):
            res[idx] = sum((pref[r][i] - (pref[l - 1][i] if l > 0 else 0)) % 2 for i in range(0, 26)) // 2 <= k

        return res
        