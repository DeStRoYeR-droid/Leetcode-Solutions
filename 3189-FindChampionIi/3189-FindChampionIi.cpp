// Last updated: 06/07/2026, 18:54:17
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        int count = 0;
        for (vector<int>& pair : edges){
            inDegree[pair[1]]++;
            if (inDegree[pair[1]] == 1) count++;
        }  
        if (count != (n-1)) return -1;

        for (int i = 0; i < n; i++){
            if (inDegree[i] == 0){
                return i;
            }
        }
        return -1;
    }
};