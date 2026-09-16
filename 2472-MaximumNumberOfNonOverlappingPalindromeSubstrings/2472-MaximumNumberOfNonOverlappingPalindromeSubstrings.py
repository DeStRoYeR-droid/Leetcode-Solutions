# Last updated: 16/09/2026, 13:32:53
class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)
        if (k == 1):
            return n

        result = 0
        i = 0

        while (i <= n - k):
            for d in (k, k + 1):
                if (i + d <= n and s[i : i + d] == s[i : i + d][::-1]):
                    result += 1
                    i += d
                    break
            else:
                i += 1
        return result