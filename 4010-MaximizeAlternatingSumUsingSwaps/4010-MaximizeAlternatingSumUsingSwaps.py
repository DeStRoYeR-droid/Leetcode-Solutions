# Last updated: 26/07/2026, 13:27:45
class Solution:
    def maxAlternatingSum(self, nums: List[int], swaps: List[List[int]]) -> int:
        n = len(nums)
        f = list(range(n))

        # Path compression DSU
        def find(x):
            if (f[x] != x):
                f[x] = find(f[x])
            return f[x]

        for (i, j) in swaps:
            f[find(i)] = find(j)

        groups = [[] for _ in range(n)]
        for i in range(n):
            groups[find(i)].append(i)

        result = 0
        for g in groups:
            if (not(g)):
                continue
            v = sorted(nums[i] for i in g)
            odd = sum(i % 2 for i in g)
            result += sum(v) - 2 * sum(v[:odd])
        return result
