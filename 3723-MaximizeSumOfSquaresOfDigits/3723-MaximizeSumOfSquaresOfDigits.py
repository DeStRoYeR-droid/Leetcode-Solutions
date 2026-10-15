# Last updated: 15/10/2026, 10:58:49
class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        return ("9" * (sum // 9) + str(sum % 9) + "0" * num)[:num] if 1 <= sum <= 9 * num else ""
