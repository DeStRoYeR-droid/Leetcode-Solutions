# Last updated: 14/09/2026, 09:16:53
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

