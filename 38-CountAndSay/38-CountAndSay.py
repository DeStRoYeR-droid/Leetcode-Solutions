# Last updated: 13/07/2026, 22:29:37
class Solution:
    def countAndSay(self, n: int) -> str:
        result = "1"
        for i in range(1,n):
            last_ch = result[0]
            count = 0
            temp = ""
            for ch in result:
                if (ch == last_ch):
                    count += 1
                else:
                    temp += str(count) + last_ch
                    count = 1
                    last_ch = ch
                    

            result = temp
            result += str(count) + last_ch
        return result