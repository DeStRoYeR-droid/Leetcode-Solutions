# Last updated: 06/07/2026, 19:05:58
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        if (str1 + str2 == str2 + str1):
            ind = gcd(len(str1), len(str2))
            return str1[:ind]
        return ""