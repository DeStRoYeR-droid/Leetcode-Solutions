# Last updated: 07/09/2026, 22:52:27
class Solution:
    def reversePrefix(self, word: str, ch: str) -> str:
        for i in range(len(word)):
            c = word[i]
            if (c == ch):
                return word[i::-1]+ word[i+1:]
        
        return word