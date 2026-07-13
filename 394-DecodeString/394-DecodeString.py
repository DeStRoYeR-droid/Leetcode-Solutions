# Last updated: 13/07/2026, 22:20:17
class Solution:
    def decodeString(self, s: str) -> str:
        alpha_stack = []
        val = 0
        temp = ""

        for char in s:
            if (char.isdigit()):
                val = (val * 10) + int(char)
            
            elif char == '[':
                alpha_stack.append((temp, val))
                val = 0
                temp = ""
            
            elif char == ']':
                string, nums = alpha_stack.pop()
                temp = string + (temp * nums)
            
            else: 
                temp += char

        return temp