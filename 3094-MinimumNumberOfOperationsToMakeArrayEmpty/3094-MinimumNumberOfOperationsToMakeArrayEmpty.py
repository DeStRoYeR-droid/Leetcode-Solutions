# Last updated: 06/07/2026, 18:54:31
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        occurences = {}
        for num in nums:
            if (num in occurences):
                occurences[num] += 1
            else:
                occurences[num] = 1
        print (occurences)
        result = 0
        for val in occurences.values():
            if (val == 1):
                return -1
            result += math.ceil(val/3)
            
        return result