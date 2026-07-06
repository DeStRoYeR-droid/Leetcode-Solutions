# Last updated: 06/07/2026, 19:04:39
class Solution:
    def findDifference(self, nums1: List[int], nums2: List[int]) -> List[List[int]]:
        set1 = set(nums1)
        set2 = set(nums2)

        return [(list(set1 - set2)), (list(set2 - set1))]