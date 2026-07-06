# Last updated: 06/07/2026, 18:52:54
class Solution:
    def compressedString(self, word: str) -> str:
        if (len(word) == 0):
            return ""
        
        result = ""
        cur = word[0]
        count = 1
        for letter in word[1:]:
            if (letter == cur):
                count += 1
                if (count > 9):
                    result += str(9) + cur
                    count = 1
            else:
                result += str(count) + cur
                count = 1
                cur = letter

        result += str(count) + cur

        return result 