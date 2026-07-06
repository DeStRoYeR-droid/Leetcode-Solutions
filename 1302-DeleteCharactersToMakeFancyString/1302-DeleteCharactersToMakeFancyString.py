# Last updated: 06/07/2026, 19:05:19
class Solution:
    def makeFancyString(self, s: str) -> str:
        result = ""
        cur = s[0]
        count = 0
        for letter in s:
            if (letter == cur):
                count += 1
                if (count < 3):
                    result += letter
            else:
                count = 1
                cur = letter
                result += letter

        return result