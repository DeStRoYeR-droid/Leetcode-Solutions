# Last updated: 15/10/2026, 11:24:23
class Solution:
    def isValid(self, s: str) -> bool:
        bracket_pair = {
            "(" : ")", 
            "{" : "}", 
            "[" : "]"
        }
        bracket_pair_inverse = dict()
        for key, value in bracket_pair.items():
            bracket_pair_inverse[value] = key

        stack = []
        for ch in s:
            if (ch in bracket_pair.keys()):
                stack.append(ch)
            else:
                if (len(stack) and stack[-1] == bracket_pair_inverse[ch]):
                    stack.pop()
                else:
                    return False

        return len(stack) == 0