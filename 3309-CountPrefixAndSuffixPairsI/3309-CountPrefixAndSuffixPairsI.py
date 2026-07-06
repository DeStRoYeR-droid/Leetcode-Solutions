# Last updated: 06/07/2026, 18:53:39
class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        result = 0

        for i in range(len(words) - 1):
            for j in range(i+1, len(words)):
                result += bool(words[j].startswith(words[i]) and words[j].endswith(words[i]))
        
        return result