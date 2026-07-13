# Last updated: 13/07/2026, 22:17:46
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        set_list = set()
        duplicate = -1
        for num in nums:
            if (num in set_list):
                duplicate = num
            set_list.add(num)

        length = len(nums)

        intended_target = length * (length + 1) // 2
        actual_sum = sum(set_list)

        removed = intended_target - actual_sum

        return [duplicate , removed]