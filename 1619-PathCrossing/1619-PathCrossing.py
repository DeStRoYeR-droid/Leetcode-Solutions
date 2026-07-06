# Last updated: 06/07/2026, 19:02:41
class Solution:
    def isPathCrossing(self, path: str) -> bool:
        visited = set()
        cur_pos = (0 , 0)
        visited.add(cur_pos)
        for char in path:
            if (char == 'N'):
                cur_pos = (cur_pos[0] , cur_pos[1] + 1)
                if (self.check(visited, cur_pos)):
                    return True
            elif (char == 'S'):
                cur_pos = (cur_pos[0] , cur_pos[1] - 1)
                if (self.check(visited, cur_pos)):
                    return True
            elif (char == 'E'):
                cur_pos = (cur_pos[0] + 1, cur_pos[1])
                if (self.check(visited, cur_pos)):
                    return True
            elif (char == 'W'):
                cur_pos = (cur_pos[0] -1, cur_pos[1])
                if (self.check(visited, cur_pos)):
                    return True
            visited.add(cur_pos)

    def check(self, visited : set, point : tuple):
        if (point in visited):
            return True
        return None