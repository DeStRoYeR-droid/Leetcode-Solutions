# Last updated: 14/09/2026, 09:26:04
class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1 = set(nums1)
        set2 = set(nums2)

        return [(list(set1 - set2)), (list(set2 - set1))]