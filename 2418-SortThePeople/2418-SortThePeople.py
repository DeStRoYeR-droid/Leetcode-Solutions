# Last updated: 07/09/2026, 22:45:25
class Solution:
    def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
        return [n for _,n in sorted(zip(heights, names), reverse = True)]