# Last updated: 15/10/2026, 11:14:13
class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        result = ""
        level = 0
        
        for c in s:
            if (c == "("):
                if (level):
                    result += c
                level += 1
            else:
                level -= 1
                if (level):
                    result += c

        return result