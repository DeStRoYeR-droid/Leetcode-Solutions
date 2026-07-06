# Last updated: 06/07/2026, 19:03:51
class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        seen = set()
        for element in arr:
            if (element * 2 in seen or element / 2 in seen):
                return True
            seen.add(element)

        return False