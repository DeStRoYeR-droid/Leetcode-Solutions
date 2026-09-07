# Last updated: 07/09/2026, 22:24:24
class Solution:
    def centeredSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        result = 0

        for i in range(n):
            curr = 0
            elements = set()

            for j in range(i, n):
                curr += nums[j]
                elements.add(nums[j])

                if (curr in elements):
                    result += 1
        return result