# Last updated: 07/09/2026, 22:42:24
class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        maxi = 0
        occur = {i : nums.count(i) for i in set(nums)}
        maxi = max(occur.values())

        result = [[] for _ in range(maxi)]

        for num in nums:
            index = 0
            while (num in result[index]):
                index += 1
            result[index].append(num)

        return result