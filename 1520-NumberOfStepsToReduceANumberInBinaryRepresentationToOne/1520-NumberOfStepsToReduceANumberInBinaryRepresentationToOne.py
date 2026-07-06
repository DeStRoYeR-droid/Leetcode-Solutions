# Last updated: 06/07/2026, 19:03:28
class Solution:
    def numSteps(self, s: str) -> int:
        if (s == "1"):
            return 0

        if (s[-1] == "0"):
            return 1 + self.numSteps(s[:-1])
        else:
            chars = [ch for ch in s]
            chars[-1] = "0"
            j = len(s) - 2
            while (j >= 0):
                if (chars[j] == "0"):
                    chars[j] = "1"
                    break
                else:
                    chars[j] = "0"
                j -= 1

            if (j == -1):
                chars = list("1") + chars
                

            return 1 + self.numSteps(''.join(chars))