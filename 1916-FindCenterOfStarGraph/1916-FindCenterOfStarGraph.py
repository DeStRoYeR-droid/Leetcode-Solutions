# Last updated: 06/07/2026, 19:00:46
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        from collections import defaultdict
        def default_val():
            return 0
        count = defaultdict(default_val)
        for v1, v2 in edges:
            count[v1] += 1
            count[v2] += 1
        for val, val2 in count.items():
            if (val2 == len(edges)):
                return val
        return -1

