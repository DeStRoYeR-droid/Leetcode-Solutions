# Last updated: 06/07/2026, 19:02:45
class Solution:
    def findLeastNumOfUniqueInts(self, arr: List[int], k: int) -> int:
        counts = {}
        for val in arr:
            if (val in counts):
                counts[val] += 1
            else:
                counts[val] = 1

        vals = sorted(list(counts.values()))
        while (k > 0):
            if (vals[0] <= k):
                sub = vals.pop(0)
            else:
                sub = vals[0]
            k -= sub
            
                
        
        return len(vals)