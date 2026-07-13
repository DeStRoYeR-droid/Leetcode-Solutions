# Last updated: 13/07/2026, 22:22:11
class Solution:
    def isUgly(self, n: int) -> bool:
        primes_allowed = [2,3,5]
        cur_index = 0
        while (cur_index < 3 and n > 1):
            if not(n % primes_allowed[cur_index]):
                n = n // primes_allowed[cur_index]
            else:
                cur_index += 1
        
        return n == 1