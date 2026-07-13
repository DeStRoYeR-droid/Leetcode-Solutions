# Last updated: 13/07/2026, 22:20:49
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        count1 = {i : nums1.count(i) for i in set(nums1)}
        count2 = {i : nums2.count(i) for i in set(nums2)}

        result = []
        for val, freq in count1.items():
            if (val in count2):
                result.extend([val] * min(freq, count2[val]))

        return result