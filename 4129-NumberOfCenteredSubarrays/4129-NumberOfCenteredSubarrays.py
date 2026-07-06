# Last updated: 06/07/2026, 18:47:53
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