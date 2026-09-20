# Last updated: 20/09/2026, 10:32:21
class Solution:
    def reverseDegree(self, s: str) -> int:
        return sum([(i + 1) * (ord('z') - ord(ch) + 1) for (i, ch) in enumerate(s)])