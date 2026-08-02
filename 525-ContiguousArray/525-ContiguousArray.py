# Last updated: 02/08/2026, 14:32:04
class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        mapping = {}
        mapping[0] = -1
        prefix, result = 0, 0
        for i, val in enumerate(nums):
            prefix += -1 if val == 0 else 1
            if (prefix in mapping):
                result = max(result, i - mapping[prefix])
            else:
                mapping[prefix] = i
        return result