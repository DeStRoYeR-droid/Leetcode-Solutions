# Last updated: 06/07/2026, 18:59:49
class Solution:
    def getLucky(self, s: str, k: int) -> int:
        result = ""
        for char in s:
            result += str(ord(char) - ord('a') + 1)

        # First iteration
        result_num = 0
        for char in result:
            result_num += int(char)

        for i in range(1, k):
            j = 0
            while (result_num > 0):
                j += result_num % 10
                result_num //= 10
            j += result_num

            result_num = j

        return result_num