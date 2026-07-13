# Last updated: 13/07/2026, 22:17:47
class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        left = 0
        right = k
        cur = sum(nums[:k])
        result = cur
        
        while (right < len(nums)):
            cur = cur - nums[left] + nums[right]
            result = max(cur, result)
            right += 1
            left += 1
        
        return result / k