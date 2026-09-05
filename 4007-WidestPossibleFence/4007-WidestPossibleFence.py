# Last updated: 05/09/2026, 16:37:37
from collections import Counter
class Solution:
    def maximumWidth(self, planks: list[int]) -> int:
        counts = Counter(planks)
        unique_planks = list(counts.items())
        n = len(unique_planks)

        scores = {}
        max_w = 0

        for val, cnt in unique_planks:
            scores[val] = scores.get(val, 0) + cnt
            if (scores[val] > max_w):
                max_w = scores[val]


        for i in range(n):
            val1, cnt1 = unique_planks[i]
            for j in range(i + 1, n):
                val2, cnt2 = unique_planks[j]

                h = val1 + val2
                scores[h] = scores.get(h, 0) + min(cnt1, cnt2)
                max_w = max(max_w, scores[h])

        for val, cnt in unique_planks:
            scores[val * 2] = scores.get(val * 2, 0) + cnt // 2
            max_w = max(max_w, scores[val * 2])

        return max_w