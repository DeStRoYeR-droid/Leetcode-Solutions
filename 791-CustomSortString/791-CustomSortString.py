# Last updated: 14/09/2026, 09:35:24
class Solution:
    def customSortString(self, order: str, s: str) -> str:
        result = ""
        freq = defaultdict(int)
        for char in s:
            freq[char] += 1
        
        for char in order:
            if (char in freq):
                result += char * freq[char]
                del freq[char]
        
        for remaining in freq:
            result = remaining * freq[remaining] + result

        return result
