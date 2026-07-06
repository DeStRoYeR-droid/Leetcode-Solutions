# Last updated: 06/07/2026, 18:55:51
class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        nums_banned = set(item for item in banned if item < n)
        result = 0
        cur_sum = 0
        for i in range(1, n+1):
            if (i in banned):
                continue
            cur_sum += i
            if (cur_sum > maxSum):
                break
            result += 1
        return result