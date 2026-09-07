# Last updated: 07/09/2026, 22:39:00
class Solution:
    def minimumPushes(self, word: str) -> int:
        return sum([1 + i // 8 for i in range(len(word))])