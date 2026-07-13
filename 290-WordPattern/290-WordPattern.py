# Last updated: 13/07/2026, 22:21:38
class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        linkChar = defaultdict(str)
        linkWord = defaultdict(str)
        words = s.split()

        if (len(words) != len(pattern)):
            return False

        for i, word in enumerate(words):
            if (linkWord[word] == "" and linkChar[pattern[i]] == ""):
                linkWord[word] = pattern[i]
                linkChar[pattern[i]] = word

            if (linkChar[pattern[i]] != word or linkWord[word] != pattern[i]):
                return False

        return True
        