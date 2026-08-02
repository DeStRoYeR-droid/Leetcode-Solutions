# Last updated: 02/08/2026, 14:10:53
from collections import Counter
class Solution:
    def minimumPushes(self, word: str) -> int:
        return sum([(1 + i // 8) * val for (i, val) in enumerate( sorted(Counter([char for char in word]).values(), reverse = True))])