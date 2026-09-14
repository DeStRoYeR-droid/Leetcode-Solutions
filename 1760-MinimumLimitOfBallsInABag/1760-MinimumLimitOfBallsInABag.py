# Last updated: 14/09/2026, 09:17:21
class Solution:
    def minimumSize(self, nums: List[int], maxOperations: int) -> int:
        low, high = 1, max(nums)
        while (low < high):
            mid = (low + high) // 2
            if sum((n-1) // mid for n in nums) <= maxOperations:
                high = mid
            else:
                low = mid + 1
        
        return high