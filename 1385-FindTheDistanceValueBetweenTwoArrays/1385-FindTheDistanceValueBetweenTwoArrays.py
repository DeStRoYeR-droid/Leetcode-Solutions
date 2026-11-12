# Last updated: 12/11/2026, 23:08:07
class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        return sum(all(abs(i - j) > d for j in arr2) for i in arr1)