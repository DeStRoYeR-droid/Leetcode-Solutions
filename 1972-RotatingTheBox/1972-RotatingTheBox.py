# Last updated: 06/07/2026, 19:00:33
class Solution:
    def rotateTheBox(self, box: List[List[str]]) -> List[List[str]]:
        for i in range(len(box)):
            for j in range(len(box[0]) - 1, -1, -1):
                if (box[i][j] == "#"):
                    k = j + 1
                    while (k < len(box[0]) and box[i][k] == "."):
                        k += 1
                    k = min(len(box[0]) - 1, k - 1)
                    box[i][j] = "."
                    box[i][k] = "#"
        result = [["." for _ in range(len(box))] for _ in range(len(box[0]))]

        for i in range(len(box[0])):
            for j in range(len(box)):
                result[i][j] = box[j][i]
            result[i] = result[i][::-1]
        
        # print (result)

        return result