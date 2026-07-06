# Last updated: 06/07/2026, 18:47:05
class Solution:
    def minCost(self, nums1: list[int], nums2: list[int]) -> int:
        c1 = {}
        c2 = {}

        for num in nums1:
            if (num in c1):
                c1[num] += 1
            else:
                c1[num] = 1

        for num in nums2:
            if (num in c2):
                c2[num] += 1
            else:
                c2[num] = 1

        total = {}
        for i, val in c1.items():
            total[i] = val
        for i, val in c2.items():
            if i in total:
                total[i] += val
            else:
                total[i] = val


        for (i, f) in total.items():
            if (f % 2):
                return -1

        swapsA, swapsB = 0, 0
        for i,f in total.items():
            needed = f // 2
            if (needed > c1.get(i, 0)):
                swapsA += (needed - c1.get(i, 0))
            if (needed > c2.get(i, 0)):
                swapsB += (needed - c2.get(i, 0))
            
        return swapsA