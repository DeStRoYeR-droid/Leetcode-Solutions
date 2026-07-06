# Last updated: 06/07/2026, 19:05:41
class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        arr1.sort()
        cur_index = 0 

        for value in arr2:
            cur_trav = cur_index
            while (cur_trav < len(arr1)):
                if (arr1[cur_trav] == value):
                    arr1[cur_index], arr1[cur_trav] = arr1[cur_trav], arr1[cur_index]
                    cur_index += 1

                cur_trav += 1

        arr1[cur_index:] = sorted(arr1[cur_index:])
        return arr1
