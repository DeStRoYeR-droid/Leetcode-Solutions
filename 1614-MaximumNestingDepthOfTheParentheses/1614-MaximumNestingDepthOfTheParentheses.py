# Last updated: 30/09/2026, 18:27:12
class Solution: maxDepth = lambda self, s: max([curr := 0] + [curr := curr + (c == '(') - (c == ')') for c in s])