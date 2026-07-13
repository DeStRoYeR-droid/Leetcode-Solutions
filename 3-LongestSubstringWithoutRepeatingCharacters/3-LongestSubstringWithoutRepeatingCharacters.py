# Last updated: 13/07/2026, 22:30:51
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if (not(s)):
            return 0

        state = {s[0] : 0}
        cur_string = s[0]
        result = 1

        for index, char in enumerate(s[1:]):
            if (char in cur_string):
                result = max(result, len(cur_string))
                cur_string = cur_string[cur_string.index(char) + 1:] + char
            else:
                cur_string += char

        return max(result, len(cur_string))