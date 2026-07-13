# Last updated: 13/07/2026, 22:20:54
class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = set("AEIOUaeiou")
        left = 0
        right = len(s) - 1
        result = list(s)
        while (left <= right):
            while (left < len(s)):
                if (s[left] not in vowels):
                    left += 1
                else:
                    break

            while (right >= 0):
                if (s[right] not in vowels):
                    right -= 1
                else:
                    break
            
            if (left >= right):
                break
            else:
                result[left], result[right] = result[right], result[left]
                right -= 1
                left += 1

        return ''.join(result)
