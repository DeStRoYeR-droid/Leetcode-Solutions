# Last updated: 06/07/2026, 18:59:27
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        for i in range(len(word)):
            c = word[i]
            if (c == ch):
                return word[i::-1]+ word[i+1:]
        
        return word