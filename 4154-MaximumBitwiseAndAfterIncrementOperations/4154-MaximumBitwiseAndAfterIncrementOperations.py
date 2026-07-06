# Last updated: 06/07/2026, 18:47:43
class Solution:
    def maximumAND(self, nums: List[int], k: int, m: int) -> int:
        result = 0

        for b in range(30, -1, -1):
            target = result | (1 << b)
            costs = []

            for x in nums:
                if (x & target == target):
                    costs.append(0)

                else:
                    diff = 0
                    for i in range(30, -1, -1):
                        bit_t = (target >> i) & 1
                        bit_x = (x >> i) & 1

                        if (bit_t):
                            diff |= (1 << i)
                            if (not(bit_x)):
                                diff |= (target & (1 << i) - 1)
                                break
                        elif bit_x:
                            diff |= (1 << i)
                    costs.append(diff - x)

            m_smallest = heapq.nsmallest(m, costs)
            if (sum(m_smallest) <= k):
                result = target
        return result