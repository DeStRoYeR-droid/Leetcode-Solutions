# Last updated: 06/07/2026, 18:59:06
class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        max_I = float('inf')
        res = [[0, 0, max_I]]

        items.sort(key = lambda x : x[0])

        for price, beauty in items:
            last_bracket = res[-1]
            if (beauty > last_bracket[1]):
                res[-1][2] = price
                res.append([price, beauty, max_I])

        print (res)
        ans = []
        for x in queries:
            for i in range(len(res) - 1, -1, -1):
                if (res[i][0] <= x):
                    ans.append(res[i][1])
                    break
        print (ans)

        return ans