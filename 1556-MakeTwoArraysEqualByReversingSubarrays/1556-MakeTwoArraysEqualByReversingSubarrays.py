# Last updated: 06/07/2026, 19:03:08
class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        dict1 = {i : target.count(i) for i in set(target)}
        dict2 = {i : arr.count(i) for i in set(arr)}

        for i in dict2:
            try:
                if (dict2[i] != dict1[i]):
                    return False
            except KeyError:
                return False
        return True