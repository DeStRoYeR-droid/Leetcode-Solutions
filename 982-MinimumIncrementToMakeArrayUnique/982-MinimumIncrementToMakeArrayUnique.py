# Last updated: 06/07/2026, 19:06:57
class Solution:
    def minIncrementForUnique(self, nums: List[int]) -> int:
        nums.sort()
        result = 0
        prev = -1
        for i in range(len(nums)):
            cur = nums[i]
            if (cur <= prev):
                result += prev - cur + 1
                cur += prev - cur + 1
            prev = cur

        return result