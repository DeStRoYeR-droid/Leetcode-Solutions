# Last updated: 07/09/2026, 22:23:19
class Solution:
    def countPairs(self, words: List[str]) -> int:
        if (len(words) <= 1):
            return 0

        n = len(words)
        m = len(words[0])

        patterns = defaultdict(int)

        for word in words:
            if (m == 1):
                pattern = tuple()
            else:
                pattern = tuple((ord(word[i]) - ord(word[i - 1])) % 26 for i in range(1, m))
            patterns[pattern] += 1

        result = 0
        print (patterns)
        for count in patterns.values():
            if (count >= 2):
                result += (count * (count - 1)) // 2
        return result