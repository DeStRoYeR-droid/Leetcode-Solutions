# Last updated: 13/07/2026, 22:19:33
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        length = len(nums)
        differences = [{} for _ in range(length)]
        result = 0
        
        for i in range(length):
            for j in range(i):
                val = nums[i] - nums[j]
                differences[i][val] = differences[i].get(val , 0) + 1

                if (val in differences[j]):
                    differences[i][val] += differences[j][val]
                    result += differences[j][val]
        
        return result