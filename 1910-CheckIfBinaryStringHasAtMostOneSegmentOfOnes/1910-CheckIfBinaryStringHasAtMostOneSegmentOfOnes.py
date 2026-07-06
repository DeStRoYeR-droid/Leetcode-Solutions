# Last updated: 06/07/2026, 19:00:50
class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        if (re.search(r'01', s)):
            return False
        return True