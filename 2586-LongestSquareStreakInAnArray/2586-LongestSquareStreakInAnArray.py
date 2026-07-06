# Last updated: 06/07/2026, 18:56:08
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