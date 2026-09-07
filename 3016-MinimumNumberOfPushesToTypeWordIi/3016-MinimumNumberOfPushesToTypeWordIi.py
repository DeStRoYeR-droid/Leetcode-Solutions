# Last updated: 07/09/2026, 22:38:50
from collections import Counter
class Solution:
    def minimumPushes(self, word: str) -> int:
        return sum([(1 + i // 8) * val for (i, val) in enumerate( sorted(Counter([char for char in word]).values(), reverse = True))])