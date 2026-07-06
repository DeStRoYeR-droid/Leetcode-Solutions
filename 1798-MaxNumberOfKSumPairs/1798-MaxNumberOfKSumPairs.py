# Last updated: 06/07/2026, 19:01:33
class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        map = defaultdict(int)
        result = 0
        for num in nums:
            find = k - num

            if (map.get(find, 0) > 0):
                result += 1
                map[find] -= 1

            else:
                map[num] = map.get(num, 0) + 1

        return result