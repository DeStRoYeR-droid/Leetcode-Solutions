# Last updated: 06/07/2026, 19:08:22
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
