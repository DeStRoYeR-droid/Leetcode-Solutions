# Last updated: 14/09/2026, 09:18:23
class Solution:
    def minPartitions(self, n: str) -> int:
        return ord(max(n)) - ord('0')