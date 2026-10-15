# Last updated: 15/10/2026, 10:58:54
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        return sum(sorted([i * i for i in nums], reverse = True)[:(len(nums) + 1) // 2]) - sum(sorted([i * i for i in nums], reverse = True)[(len(nums) + 1) // 2:])