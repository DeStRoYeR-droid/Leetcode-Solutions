# Last updated: 07/09/2026, 22:44:12
class Solution:
    def longestSquareStreak(self, nums: List[int]) -> int:
        result = -1
        num_set = set(nums)
        for num in num_set:
            cur = 1
            while (num*num in num_set):
                cur += 1
                num *= num
            
            if (cur != 1):
                result = max(result, cur)
        return result