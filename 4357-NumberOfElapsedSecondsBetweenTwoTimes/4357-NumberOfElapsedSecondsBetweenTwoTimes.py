# Last updated: 13/07/2026, 21:45:26
class Solution:
    def secondsBetweenTimes(self, startTime: str, endTime: str) -> int:
        t1 = list(map(int, startTime.split(":")))
        t2 = list(map(int, endTime.split(":")))

        return (t2[0] - t1[0]) * 3600 + (t2[1] - t1[1]) * 60 + (t2[2] - t1[2])