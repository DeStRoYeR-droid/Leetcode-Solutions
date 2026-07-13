# Last updated: 13/07/2026, 22:30:54
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        result = dict()
        for i in range(len(nums)):
            if (target - nums[i] in result):
                return [result[target-nums[i]] , i]
            result[nums[i]] = i
        return [-1,-1]