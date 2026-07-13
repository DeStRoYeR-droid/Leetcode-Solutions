# Last updated: 13/07/2026, 22:29:00
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if not matrix:
            return []

        result = []
        top, bottom = 0, len(matrix) - 1
        left, right = 0, len(matrix[0]) - 1

        while top <= bottom and left <= right:
            # Traverse from left to right
            for col in range(left, right + 1):
                result.append(matrix[top][col])
            top += 1

            # Traverse downwards on the right boundary
            for row in range(top, bottom + 1):
                result.append(matrix[row][right])
            right -= 1

            # Traverse from right to left along the bottom row
            if top <= bottom:
                for col in range(right, left - 1, -1):
                    result.append(matrix[bottom][col])
                bottom -= 1

            # Traverse upwards on the left boundary
            if left <= right:
                for row in range(bottom, top - 1, -1):
                    result.append(matrix[row][left])
                left += 1

        return result