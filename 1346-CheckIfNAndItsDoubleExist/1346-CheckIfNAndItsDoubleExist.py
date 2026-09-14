# Last updated: 14/09/2026, 09:24:06
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        seen = set()
        for element in arr:
            if (element * 2 in seen or element / 2 in seen):
                return True
            seen.add(element)

        return False