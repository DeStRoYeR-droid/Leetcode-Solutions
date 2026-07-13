# Last updated: 13/07/2026, 22:20:09
class Solution:
    def longestPalindrome(self, s: str) -> int:
        charSet = set()
        result = 0
        for char in s:
            if (char in charSet):
                charSet.remove(char)
                result += 2
            else:
                charSet.add(char)
        
        if (charSet):
            result += 1
            
        return result