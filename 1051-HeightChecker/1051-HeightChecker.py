# Last updated: 14/09/2026, 09:29:10
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        expected = list(heights)
        expected.sort()

        return sum([expected[i] != heights[i] for i in range(len(heights))])