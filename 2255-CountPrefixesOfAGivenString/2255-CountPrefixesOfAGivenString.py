# Last updated: 07/09/2026, 22:48:05
class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        result = 0
        for word in words:
            if (s.startswith(word)):
                result += 1
        return result