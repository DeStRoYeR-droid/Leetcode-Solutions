# Last updated: 14/09/2026, 09:22:46
class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        words = sorted(words, key = len)
        result = []
        for (i, word) in enumerate(words):
            for next in words[i+1:]:
                if (word in next):
                    result.append(word)
                    break

        return result