# Last updated: 06/07/2026, 18:57:46
class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        result = 0
        for word in words:
            if (s.startswith(word)):
                result += 1
        return result