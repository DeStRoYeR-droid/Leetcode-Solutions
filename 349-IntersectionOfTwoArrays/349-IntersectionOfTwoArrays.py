# Last updated: 13/07/2026, 22:20:50
class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return [val for val in set(nums1) if val in set(nums2)]