# Last updated: 15/10/2026, 11:04:28
class Solution:
    def sumOfSquares(self, nums: List[int]) -> int:
        return sum(v * v for i, v in enumerate(nums) if len(nums) % (i + 1) == 0)