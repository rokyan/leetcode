# https://leetcode.com/problems/minimum-health-to-beat-game/description/

class Solution:
    def minimumHealth(self, damage: List[int], armor: int) -> int:
        total, worst = 0, 0

        for d in damage:
            total += d
            worst = max(worst, d)

        return 1 + total - min(worst, armor)        