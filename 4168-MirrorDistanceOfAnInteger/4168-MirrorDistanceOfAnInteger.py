# Last updated: 06/07/2026, 18:47:46
class Solution:
    def mirrorDistance(self, n: int) -> int:
        return abs(n - int(str(n)[::-1]))