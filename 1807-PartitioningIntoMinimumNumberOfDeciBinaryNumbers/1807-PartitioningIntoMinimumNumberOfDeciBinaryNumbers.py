# Last updated: 06/07/2026, 19:01:28
class Solution:
    def minPartitions(self, n: str) -> int:
        return ord(max(n)) - ord('0')