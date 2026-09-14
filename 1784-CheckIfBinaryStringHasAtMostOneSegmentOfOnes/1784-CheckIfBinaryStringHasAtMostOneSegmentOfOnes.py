# Last updated: 14/09/2026, 09:17:02
class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        if (re.search(r'01', s)):
            return False
        return True