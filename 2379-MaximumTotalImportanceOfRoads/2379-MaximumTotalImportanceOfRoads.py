# Last updated: 06/07/2026, 18:57:37
class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        def def_val():
            return 0
        counts = defaultdict(def_val)
        for v1,v2 in roads:
            counts[v1] += 1
            counts[v2] += 1
        counts_list = list(counts.items())
        counts_list.sort(key=itemgetter(1), reverse = True)
        allocated = {}
        cur = n
        for index, val1 in enumerate(counts_list):
            allocated[val1[0]] = cur
            cur -= 1
        
        result = 0
        for e1,e2 in roads:
            result += allocated[e1] + allocated[e2]
        return result