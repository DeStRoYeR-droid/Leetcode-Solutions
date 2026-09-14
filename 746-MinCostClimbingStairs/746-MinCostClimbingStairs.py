# Last updated: 14/09/2026, 09:37:12
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp_array = [0] * len(cost)
        dp_array[0] = cost[0]
        dp_array[1] = cost[1]

        for i in range(2, len(cost)):
            dp_array[i] = cost[i] + min(dp_array[i-1], dp_array[i-2])
        
        return min(dp_array[len(cost) -1 ], dp_array[len(cost) - 2])