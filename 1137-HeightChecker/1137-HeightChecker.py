# Last updated: 06/07/2026, 19:05:54
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        expected = list(heights)
        expected.sort()

        return sum([expected[i] != heights[i] for i in range(len(heights))])