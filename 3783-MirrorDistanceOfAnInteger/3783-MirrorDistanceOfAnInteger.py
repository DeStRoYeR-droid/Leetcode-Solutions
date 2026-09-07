# Last updated: 07/09/2026, 22:23:49
class Solution:
    def mirrorDistance(self, n: int) -> int:
        return abs(n - int(str(n)[::-1]))