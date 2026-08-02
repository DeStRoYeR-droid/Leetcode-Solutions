# Last updated: 02/08/2026, 14:10:58
class Solution:
    def minimumPushes(self, word: str) -> int:
        return sum([1 + i // 8 for i in range(len(word))])