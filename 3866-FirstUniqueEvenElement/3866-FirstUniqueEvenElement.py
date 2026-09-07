# Last updated: 07/09/2026, 22:22:21
class Solution:
    def firstUniqueEven(self, nums: list[int]) -> int:
        f = {}
        for num in nums:
            if (num in f):
                f[num] += 1
            else:
                f[num] = 1

        for num in nums:
            if (f[num] == 1 and num % 2 == 0):
                return num

        return -1