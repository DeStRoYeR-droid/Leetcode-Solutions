# Last updated: 30/09/2026, 18:15:46
class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        return next((i for i, num in enumerate(nums) if sum(map(int, str(num))) == i), -1)