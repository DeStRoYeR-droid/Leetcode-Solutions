# Last updated: 13/07/2026, 22:23:58
class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        while (n > 3):
            p = 0
            while (n > 0):
                p += (n % 10) ** 2
                n = n // 10
            n = p
            if (n in seen):
                return False
            else:
                seen.add(p)
            
        
        return n == 1