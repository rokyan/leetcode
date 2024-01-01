# https://leetcode.com/problems/high-access-employees/description/

class Solution:
    def findHighAccessEmployees(self, access_times: List[List[str]]) -> List[str]:
        all = defaultdict(list)

        for time in access_times:
            all[time[0]].append(int(time[1][0:2]) * 60 + int(time[1][2:]))

        res = []

        for k, v in all.items():
            if len(v) < 3:
                continue
            v.sort()
            for i in range(2, len(v)):
                if v[i] - v[i - 2] < 60:
                    res.append(k)
                    break

        return res
        