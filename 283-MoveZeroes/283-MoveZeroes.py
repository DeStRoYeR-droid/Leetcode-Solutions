# Last updated: 13/07/2026, 22:21:47
class Solution:
    def find_next_zero(self, nums: List[int], start) -> int:
        for i in range(start, len(nums)):
            if (nums[i] == 0):
                return i
        
        return -1

    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        non_zero_pointer = self.find_next_zero(nums, 0)
        if (non_zero_pointer == -1):
            return
        
        right = non_zero_pointer + 1
        while (right < len(nums)):
            if (nums[right] != 0):
                nums[right], nums[non_zero_pointer] = nums[non_zero_pointer], nums[right]
                non_zero_pointer = self.find_next_zero(nums, non_zero_pointer)
                if (non_zero_pointer == -1):
                    return
            right += 1