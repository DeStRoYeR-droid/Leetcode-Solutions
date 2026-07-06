# Last updated: 06/07/2026, 19:03:37
class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        result = []
        for row in matrix:
            # Find minimum
            index = 0
            for i in range(1, len(row)):
                if (row[i] < row[index]):
                    index = i
            
            isMax = True
            for i in range(0, len(matrix)):
                if (row[index] < matrix[i][index]):
                    isMax = False
                    break
            
            if (isMax):
                result.append(row[index])

        return result