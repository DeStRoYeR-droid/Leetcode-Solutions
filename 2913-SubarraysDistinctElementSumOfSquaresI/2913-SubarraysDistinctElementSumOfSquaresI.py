# Last updated: 31/10/2026, 19:56:14
class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        return sum(len(set(nums[i:i+l])) ** 2 for i in range(len(nums)) for l in range(1, len(nums) - i + 1))