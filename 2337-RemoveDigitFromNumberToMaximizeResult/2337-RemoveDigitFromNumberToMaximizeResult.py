# Last updated: 06/07/2026, 18:57:49
class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        index = len(number) - 1
        vals = []
        while (index > -1):
            if (number[index] == digit):
                vals.append(int(number[:index] + number[index+1:]))
            index -= 1

        return str(max(vals))