# Last updated: 12/11/2026, 22:49:33
class Solution:
    def minMergedInteger(self, n: list[int]) -> int:
        return min([int(str(n[i]) + str(n[i+1])) for i in range(0, len(n), 2)])